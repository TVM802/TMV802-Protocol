#include "hal-api.h"
#include <deque>
#include <winsock2.h>
#include <string>
#include <sstream>
#include <math.h>
#include <cmath>

#define NUM_STEPS 32808

using namespace System;

//declarations-------------------------------------------------------------------
const int MAX_X = 0xd0c168;
const int MAX_Y = 0xd6bca8;


WSADATA wsa;
SOCKET s;
struct sockaddr_in server;

std::deque<unsigned int> CommandQueue;
bool SpeedFast = false;
bool vac1 = false;
bool vac2 = false;
bool blow1 = false;
bool blow2 = false;
bool pres1 = false;
bool pres2 = false;
bool strip = false;
bool yneg = true;
bool ypos = true;
bool xneg = true;
bool xpos = true;
bool pause = false;
bool pause_led = false;
bool start = false;
bool run_led = false;
bool dot_led = false;
bool con_led = false;
bool cam_led = false;
bool status_led = false;
bool step = false;
bool pump_stat = false;
bool pick = false;
bool strip_activated = false;
bool x_neg_active = false;
bool x_pos_active = false;
bool y_neg_active = false;
bool y_pos_active = false;
bool homing = false;
bool homed = false;
bool speed_button = false;
bool wait = true;

int speed_command = 0x00000006;
int x_accel = 0x03;
int x_descel = 0x03;
int x_speed = 0x01;
int y_accel = 0x03;
int y_descel = 0x03;
int y_speed = 0x01;
int strip_accel = 0x03;
int strip_descel = 0x03;
int strip_speed = 0x03e8;
int r1_accel = 0x03;
int r1_descel = 0x03;
int r1_speed = 0x01f4;
int r2_accel = 0x03;
int r2_descel = 0x03;
int r2_speed = 0x01f4;
int z_accel = 0x03;
int z_descel = 0x03;
int z_speed = 0x01;
int spd = 1;
int accel = 3;
int descel = 3;

int X_pos_raw = 0;
int Y_pos_raw = 0;

int strip_pos;

//int X_target = 0;

int X_pos = 0;
int Y_pos = 0;
double A1_pos = 0;
double A2_pos = 0;
double N_pos = 0;

static unsigned char RecvBuffer[2000];
static int BufFilled = 0;

std::string label2_text = "null";
std::string label_text = "null";
std::string label_text_0 = "null";
std::string label_text_1 = "null";
std::string label_text_2 = "null";
std::string label_text_3 = "null";
std::string label_text_4 = "null";
std::string label_text_5 = "null";
std::string label_text_6 = "null";
std::string label_text_7 = "null";
std::string label_text_8 = "null";
std::string label_text_9 = "null";
std::string label_text_10 = "null";
std::string label_text_11 = "null";
char text_buffer[33];
char text_buffer_0[33];
char text_buffer_1[33];
char text_buffer_2[33];
char text_buffer_3[33];
char text_buffer_4[33];
char text_buffer_5[33];
char text_buffer_6[33];
char text_buffer_7[33];
char text_buffer_8[33];
char text_buffer_9[33];
char text_buffer_10[33];
char text_buffer_11[33];
char test_buffer[33];
unsigned int axis_scan = 0;
unsigned int axis_lim = 0;
unsigned int pick_scan = 0;
unsigned int pick_lim = 0;

const unsigned char ReqStatus[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const unsigned char Req15[8] = { 0x15, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00 };
const unsigned char Req14[8] = { 0x14, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00 };


//functions----------------------------------------------------------------------
int NetworkStart() {
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		//printf("Failed. Error Code : %d",WSAGetLastError());
		return 1;
	}
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		//printf("Could not create socket : %d" , WSAGetLastError());
		return 2;
	}

	server.sin_addr.s_addr = inet_addr("192.168.0.8");
	server.sin_family = AF_INET;
	server.sin_port = htons(701);

	//Connect to remote server
	if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		//puts("connect error");
		return 3;
	}

	int Timeout = 1;

	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char*)&Timeout, sizeof(Timeout));
	return 0;
}

//this function only used for debug
std::string StringPad(std::string str) {
	std::string test = str;
	if (test.length() < 8) {
		int pad = 8 - test.length();
		for (int i = 0; i < pad; i++) {
			test = "0" + test;
		}
	}
	return test;
}

void SendSlowCommand() {
	CommandQueue.push_back(0x06); //speed setting command
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x03); // -> 5
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x03); // -> 5
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x03);  // -> 5
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x03);   // -> 5
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x03e8); // 1000
	CommandQueue.push_back(0x01);   // 1
	CommandQueue.push_back(0x01);   // 1
	CommandQueue.push_back(0x01f4); // 500
	CommandQueue.push_back(0x01);   // 1
	CommandQueue.push_back(0x01f4); // 500
}

void SendFastCommand() {
	CommandQueue.push_back(0x020006);
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x05);
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x05);
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x05);
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x05);
	CommandQueue.push_back(0x03);
	CommandQueue.push_back(0x07d0); // 2000
	CommandQueue.push_back(0x03e8); // 500
	CommandQueue.push_back(0x05dc); // 1500
	CommandQueue.push_back(0x07d0); // 2000
	CommandQueue.push_back(0x05dc); // 1500
	CommandQueue.push_back(0x07d0); // 2000
}

void SendSpeedCommand() {

	CommandQueue.push_back(speed_command);
	CommandQueue.push_back(strip_accel);
	CommandQueue.push_back(z_accel);
	CommandQueue.push_back(x_accel);
	CommandQueue.push_back(r1_accel);
	CommandQueue.push_back(y_accel);
	CommandQueue.push_back(r2_accel);
	CommandQueue.push_back(strip_descel);
	CommandQueue.push_back(z_descel);
	CommandQueue.push_back(x_descel);
	CommandQueue.push_back(r1_descel);
	CommandQueue.push_back(y_descel);
	CommandQueue.push_back(r2_descel);
	CommandQueue.push_back(strip_speed);
	CommandQueue.push_back(z_speed);
	CommandQueue.push_back(x_speed);
	CommandQueue.push_back(r1_speed);
	CommandQueue.push_back(y_speed);
	CommandQueue.push_back(r2_speed);
}

void GracefulStart() {
	//this does something
	CommandQueue.push_back(0x05);
	CommandQueue.push_back(0x00);
	//this turns off ConMove LED
	CommandQueue.push_back(0x15);
	CommandQueue.push_back(0x80);
	//this turns on DotMove LED
	CommandQueue.push_back(0x14);
	CommandQueue.push_back(0x0100);
	//this turns on the lamp
	CommandQueue.push_back(0x14);
	CommandQueue.push_back(0x0200);
	//this is a button lockout?
	CommandQueue.push_back(0x0b);
	//this does something
	CommandQueue.push_back(0x15);
	CommandQueue.push_back(0x4800);
	//------------------following emulates manual mode press
	//CommandQueue.push_back(0x0b);
	//this does something
	//CommandQueue.push_back(0x15);
	//CommandQueue.push_back(0x4020);
	//this does something else
	//CommandQueue.push_back(0x15);
	//CommandQueue.push_back(0x20);
}

void step_x_neg() {
	if (!(axis_lim & 0b00000010)) {
		int X_target = X_pos_raw - 0x3e8;
		//SendSlowCommand();
		CommandQueue.push_back(0x040008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(X_target);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
	}
}
void move_x_neg() {
	if (!(axis_lim & 0b00000010)) {
		//SendFastCommand();
		CommandQueue.push_back(0x040008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0xfe0b63c0);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
	}
}

void step_x_pos() {
	if (!(axis_lim & 0b00000001)) {
		int X_target = X_pos_raw + 0x3e8;
		//SendSlowCommand();
		CommandQueue.push_back(0x040008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(X_target);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
	}
}
void move_x_pos() {
	if (!(axis_lim & 0b00000001)) {
		//SendFastCommand();
		//SendTestCommand();
		//SendSpeedCommand(speed, accel, descel);
		CommandQueue.push_back(0x040008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x01f49c40);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
	}
}

void step_y_neg() {
	if (!(axis_lim & 0b00001000)) {
		int Y_target = Y_pos_raw - 0x3e8;
		//SendSlowCommand();
		CommandQueue.push_back(0x100008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(Y_target);
		CommandQueue.push_back(0x00);
	}
}
void move_y_neg() {
	if (!(axis_lim & 0b00001000)) {
		//SendFastCommand();
		CommandQueue.push_back(0x100008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0xfe0b63c0);
		CommandQueue.push_back(0x00);
	}
}

void step_y_pos() {
	if (!(axis_lim & 0b00000100)) {
		int Y_target = Y_pos_raw + 0x3e8;
		//SendSlowCommand();
		CommandQueue.push_back(0x100008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(Y_target);
		CommandQueue.push_back(0x00);
	}
}
void move_y_pos() {
	if (!(axis_lim & 0b00000100)) {
		//SendFastCommand();
		CommandQueue.push_back(0x100008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x01f49c40);
		CommandQueue.push_back(0x00);
	}
}

void GoHome(bool reset) {
	static int stage = 0;
	if (reset) {
		stage = 0;
	}
	else {
		static int step = 0;
		switch (stage) {
		case 0: {			//move y towards y+ limit
			CommandQueue.push_back(0x100008);
			CommandQueue.push_back(0x00);
			CommandQueue.push_back(0x00);
			CommandQueue.push_back(0x00);
			CommandQueue.push_back(0x00);
			CommandQueue.push_back(0x01f49c40);
			CommandQueue.push_back(0x00);
			stage = 1;
			break;
		}
		case 1: {
			if (axis_lim & 0b00000100) {  //reached y+ limit
				step = Y_pos_raw - 0x280a0;
				CommandQueue.push_back(0x100008); //move y back a little
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(step);
				CommandQueue.push_back(0x00);
				//move_y_neg();
				stage = 2;
			}
			break;
		}
		case 2: {
			if (Y_pos_raw == step) {//finished moving back
				step = Y_pos_raw + 0x280a0;
				CommandQueue.push_back(0x100008); //move forward to limit
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(step);
				CommandQueue.push_back(0x00);
				stage = 3;
			}
			break;
		}
		case 3: {
			if (axis_lim & 0b00000100) {  //reached y+ limit again
										  //SendSpeedCommand(3, 3, 3);
				CommandQueue.push_back(0x100007); //write limit to register
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(MAX_Y);
				CommandQueue.push_back(0x00);
				stage = 4;
			}
			break;
		}
		case 4: {
			CommandQueue.push_back(0x040008);	//move to x+ limit
			CommandQueue.push_back(0x00);
			CommandQueue.push_back(0x00);
			CommandQueue.push_back(0x01f49c40);
			CommandQueue.push_back(0x00);
			CommandQueue.push_back(0x00);
			CommandQueue.push_back(0x00);
			stage = 5;
			break;
		}
		case 5: {
			if (axis_lim & 0b00000001) { //if reached x- limit
				step = X_pos_raw - 0x280a0;
				CommandQueue.push_back(0x040008);	//move x back a little
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(step);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				stage = 6;
			}
			break;
		}
		case 6: {
			if (X_pos_raw == step) { //reached desired location
				step = X_pos_raw + 0x280a0;
				CommandQueue.push_back(0x040008);	//move x back to limit
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(step);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				stage = 7;
			}
			break;
		}
		case 7: {
			if (axis_lim & 0b00000001) { //reached x+ limit again
										 //SendSpeedCommand(3, 3, 3);
				CommandQueue.push_back(0x040007); //write limit to register
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(MAX_X);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				stage = 0;
				homing = false;
				homed = true;
			}
			break;
		}
		default: {
			stage = 0;
			step = 0;
			homing = false;
			//do nothing
		}
		}
	}
}

void beep_on() {
	CommandQueue.push_back(0x14);
	CommandQueue.push_back(0x0800);
}

void beep_off() {
	CommandQueue.push_back(0x15);
	CommandQueue.push_back(0x0800);
}

int ToClosestStep(int value) {
	int error = value % 1000;
	int corrected = 0;
	//X_target_raw = X_target_raw + 1000 - error;
	if (error > 500)
		corrected = value + (1000 - error); //if error greater than half step, round down to nearest step
	else
		corrected = value - (error);		//if error less than half step, round up to nearest step
	return corrected;
}

void ShiftRecvBuffer(int Size) {
	if (Size >= BufFilled) {
		BufFilled = 0;
		return;
	}

	BufFilled -= Size;
	for (int i = 0; i < BufFilled; i++)
		RecvBuffer[i] = RecvBuffer[i + Size];

}

void FillBuffer(unsigned char* Buffer, signed int Number) {
	unsigned N = Number;
	for (int i = 0; i < 4; i++) {
		*Buffer = N & 0xFF;
		N >>= 8;
		Buffer++;
	}
}

int BuildNumber(const unsigned char* p, int size) {

	int Res = 0;
	for (int i = 0; i < size; i++) {
		Res <<= 8;
		Res += p[size - 1 - i];
	}

	return Res;
};

bool CheckBit(const unsigned char* p, int bit) {
	int byteindex = bit / 32;
	int bitindex = 32 - bit % 32;
	int word = BuildNumber(p + byteindex * 4, 4);
	return ((word & (1 << bitindex)) >> bitindex);
}

void ProcessResponse() {
	int Size = recv(s, (char*)RecvBuffer + BufFilled, 2000 - BufFilled, 0);

	if (Size > 0)
		BufFilled += Size;

	while (BufFilled > 2) {

		unsigned int FirstWord = BuildNumber(RecvBuffer, 2);
		unsigned int RecvWord_0 = BuildNumber(RecvBuffer, 4); //first 2 bytes
		unsigned int RecvWord_1 = BuildNumber(RecvBuffer + 4, 4); //second 2 bytes
		unsigned int RecvWord_2 = BuildNumber(RecvBuffer + 8, 4);
		unsigned int RecvWord_3 = BuildNumber(RecvBuffer + 12, 4);
		unsigned int RecvWord_4 = BuildNumber(RecvBuffer + 16, 4);
		unsigned int RecvWord_5 = BuildNumber(RecvBuffer + 20, 4);
		unsigned int RecvWord_6 = BuildNumber(RecvBuffer + 24, 4);
		unsigned int RecvWord_7 = BuildNumber(RecvBuffer + 28, 4);
		unsigned int RecvWord_8 = BuildNumber(RecvBuffer + 32, 4);
		unsigned int RecvWord_9 = BuildNumber(RecvBuffer + 36, 4);
		unsigned int RecvWord_10 = BuildNumber(RecvBuffer + 40, 4);
		unsigned int RecvWord_11 = BuildNumber(RecvBuffer + 44, 4);


		switch (FirstWord) {
		case 0x00: {
			if (BufFilled < 44)
				return;
			// Parse Status word
			int SpeedWord = BuildNumber(RecvBuffer + 4, 2);

			//THIS IS MY TEST VARIABLE TO DISPLAY IN LABEL 2-------------------------------------------
			int test = BuildNumber(RecvBuffer + 4, 1);

			int axis_lim_old = axis_lim;
			axis_lim = BuildNumber(RecvBuffer + 8, 1);
			pick_lim = CheckBit(RecvBuffer, 77);

			int pick_comm = BuildNumber(RecvBuffer + 4, 2);
			pick = (pick_comm & (1 << 14)) >> 14;

			vac1 = CheckBit(RecvBuffer, 62);
			vac2 = CheckBit(RecvBuffer, 51);
			blow1 = CheckBit(RecvBuffer, 63);
			blow2 = CheckBit(RecvBuffer, 52);
			pres1 = CheckBit(RecvBuffer, 92);
			pres2 = CheckBit(RecvBuffer, 76);
			strip = CheckBit(RecvBuffer, 319);

			//checking buttons on machine
			int buttons = BuildNumber(RecvBuffer + 8, 4);
			bool speed_old = speed_button;
			yneg = (buttons & (1 << 11)) >> 11;
			ypos = (buttons & (1 << 18)) >> 18;
			xneg = (buttons & (1 << 16)) >> 16;
			xpos = (buttons & (1 << 12)) >> 12;
			pause = (buttons & (1 << 14)) >> 14;
			start = (buttons & (1 << 15)) >> 15;
			step = (buttons & (1 << 13)) >> 13;
			speed_button = (buttons & (1 << 17)) >> 17;

			//checking LED status
			int status = BuildNumber(RecvBuffer + 4, 2);
			pause_led = (status & (1 << 6)) >> 6;
			run_led = (status & (1 << 5)) >> 5;
			dot_led = (status & (1 << 8)) >> 8;
			con_led = (status & (1 << 7)) >> 7;
			cam_led = (status & (1 << 9)) >> 9;

			pump_stat = CheckBit(RecvBuffer, 61);

			//getting x position
			X_pos_raw = BuildNumber(RecvBuffer + 20, 4); //X_pos_raw contains absolute postion
			float X_pos_fl = X_pos_raw / 32808.00; //divide by stepsize returns position in mm (original was 32808)
			X_pos = X_pos_fl * 1000; // convert to microns

			//getting y position
			Y_pos_raw = BuildNumber(RecvBuffer + 28, 4);
			float Y_pos_fl = Y_pos_raw / 32808.00; //divide by stepsize (original was 32808)
			Y_pos = Y_pos_fl * 1000;

			//getting A1 rotation
			int A1_pos_raw = BuildNumber(RecvBuffer + 24, 4);
			A1_pos = A1_pos_raw / 4444.44;
			A1_pos = round(A1_pos * 100) / 100;

			//getting A2 rotation
			int A2_pos_raw = BuildNumber(RecvBuffer + 32, 4);
			A2_pos = A2_pos_raw / 4444.44;
			A2_pos = round(A2_pos * 100) / 100;

			//getting nozzle position
			int nozzle = BuildNumber(RecvBuffer + 16, 4);
			double slope = 1;
			int step = 78000;
			double offset = 0;
			int nozzle_abs = abs(nozzle);
			//linear interpolation of nozzle position
			if (nozzle_abs >= 0 && nozzle_abs <= 78000) {
				slope = (5.13 - 0) / step;
				offset = 0;
			}
			else if (nozzle_abs > 78000 && nozzle_abs <= 156000) {
				slope = (9.78 - 5.13) / step;
				offset = 0.48;
			}
			else if (nozzle_abs > 156000 && nozzle_abs <= 234000) {
				slope = (13.51 - 9.78) / step;
				offset = 2.32;
			}
			else {
				slope = (15.99 - 13.51) / step;
				offset = 6.07;
			}
			if (nozzle < 0)
				offset = -offset;
			N_pos = nozzle * slope + offset;
			N_pos = round(N_pos * 100) / 100;

			//Check strip position
			strip_pos = BuildNumber(RecvBuffer + 12, 4);
			if (strip_pos == 0xffe17b80) {   //807be1ff
				CommandQueue.push_back(0x010007);      //if strip has reached its destination, reset that register
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				CommandQueue.push_back(0x00);
				strip_activated = false; //allow button operation again
			}


			bool slow_bit = (SpeedWord & (1 << 8)) >> 8;
			bool fast_bit = (SpeedWord & (1 << 7)) >> 7;
			if (fast_bit && !slow_bit)
				SpeedFast = true;
			else if (slow_bit && !fast_bit)
				SpeedFast = false;
			if ((speed_old != speed_button) && !speed_button) { // if the speed button has been pressed down (does not activate on release)
				if (SpeedFast) {							//send appropriate commands to change speed
					CommandQueue.push_back(0x15);
					CommandQueue.push_back(0x80);
					CommandQueue.push_back(0x14);
					CommandQueue.push_back(0x100);
				}
				else {
					CommandQueue.push_back(0x14);
					CommandQueue.push_back(0x80);
					CommandQueue.push_back(0x15);
					CommandQueue.push_back(0x100);
				}
			}

			//homing
			if (homing) {
				GoHome(0);
			}
			else {
				GoHome(1);
			}


			//turn on beeper if axis limit reached?
			/*if (axis_lim_old != axis_lim) {
			if (axis_lim & 0b00001111)
			beep_on();
			else
			beep_off();
			}*/

			//THIS IS JUST FOR DEBUG*****************************************************************************************
			//process integers into hex based chars in 4 byte increments
			itoa(RecvWord_0, text_buffer_0, 16);
			itoa(RecvWord_1, text_buffer_1, 16);
			itoa(RecvWord_2, text_buffer_2, 16);
			itoa(RecvWord_3, text_buffer_3, 16);
			itoa(RecvWord_4, text_buffer_4, 16);
			itoa(RecvWord_5, text_buffer_5, 16);
			itoa(RecvWord_6, text_buffer_6, 16);
			itoa(RecvWord_7, text_buffer_7, 16);
			itoa(RecvWord_8, text_buffer_8, 16);
			itoa(RecvWord_9, text_buffer_9, 16);
			itoa(RecvWord_10, text_buffer_10, 16);
			itoa(RecvWord_11, text_buffer_11, 16);
			//make each char array into a std string
			label_text_0 = text_buffer_0;
			label_text_1 = text_buffer_1;
			label_text_2 = text_buffer_2;
			label_text_3 = text_buffer_3;
			label_text_4 = text_buffer_4;
			label_text_5 = text_buffer_5;
			label_text_6 = text_buffer_6;
			label_text_7 = text_buffer_7;
			label_text_8 = text_buffer_8;
			label_text_9 = text_buffer_9;
			label_text_10 = text_buffer_10;
			label_text_11 = text_buffer_11;
			// pad strings with 0s
			label_text_0 = StringPad(label_text_0);
			label_text_1 = StringPad(label_text_1);
			label_text_2 = StringPad(label_text_2);
			label_text_3 = StringPad(label_text_3);
			label_text_4 = StringPad(label_text_4);
			label_text_5 = StringPad(label_text_5);
			label_text_6 = StringPad(label_text_6);
			label_text_7 = StringPad(label_text_7);
			label_text_8 = StringPad(label_text_8);
			label_text_9 = StringPad(label_text_9);
			label_text_10 = StringPad(label_text_10);
			label_text_11 = StringPad(label_text_11);
			//concatenate all strings into one for display
			label_text = label_text_0 + " " + label_text_1 + " " + label_text_2 + " " + label_text_3 + " " + label_text_4
				+ " " + label_text_5 + " " + label_text_6 + " " + label_text_7 + " " + label_text_8 + " " + label_text_9 + " " + label_text_10 + " " + label_text_11;

			//testing and stuff
			//itoa(test, test_buffer, 16);
			//label2_text = test_buffer;
			//DEBUG ENDS***************************************************************************************************************************


			ShiftRecvBuffer(44);
		}
		case 0x1:
			ShiftRecvBuffer(12);
			break;

		case 0x14:
		case 0x15:

			if (BufFilled < 0x2)
				return;
			ShiftRecvBuffer(2);
			break;
		case  0x8: {
			ShiftRecvBuffer(2);
			break;
		}
		case 0x7: {
			ShiftRecvBuffer(2);
			break;
		}
		case 0x6: {
			ShiftRecvBuffer(2);
			break;
		}
		case 0x9: {
			ShiftRecvBuffer(2);
			break;
		}

		default:
			ShiftRecvBuffer(4);

		}
	};

	static int SendReadRegisterCount = 10;
	SendReadRegisterCount--;
	if (SendReadRegisterCount == 0) {
		SendReadRegisterCount = 10;
		const char ReadReq[12] = { 0x01, 0x00, 0x00, 0x00,
			0xf4, 0x01, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00
		};
		int res = send(s, ReadReq, sizeof(ReadReq), 0);
		return;

	}

	if (CommandQueue.size() == 0) {
		// Send out new Status Request
		int res = send(s, (char*)ReqStatus, sizeof(ReqStatus), 0);
		return;
	}

	while (CommandQueue.size()) {
		unsigned int Command = CommandQueue.front();
		CommandQueue.pop_front();

		unsigned char SendBuffer[200];

		switch (Command) {
			//------------------------cases 15 and 14 on/off commands--------------------------
		case 0x15:
		{
			//in this case we only send 2 bytes, because this is a two byte command
			FillBuffer(SendBuffer, 0x15); //pad the send buffer with 0s after the 0x15 command
			int SecondByte = CommandQueue.front(); //grab second bytes meaningful data
			CommandQueue.pop_front();

			FillBuffer(SendBuffer + 4, SecondByte); //pad the meaningful data with 0s and push into the second byte of send buffer

			send(s, (char*)SendBuffer, 8, 0); //send the send buffer
			break;
		}
		case 0x14: {
			//same as case 0x14, only command is different
			FillBuffer(SendBuffer, 0x14);
			int SecondByte = CommandQueue.front();
			CommandQueue.pop_front();

			FillBuffer(SendBuffer + 4, SecondByte);

			send(s, (char*)SendBuffer, 8, 0);
			break;
		}
		//-------------------case "8" move commands----------------------------------

		case 0x010008:
		case 0x080008:
		case 0x200008:
		case 0x020008:
		case 0x100008:
		case 0x040008:
			FillBuffer(SendBuffer, Command);
			for (int i = 0; i < 6; i++) {
				int next_byte = CommandQueue.front();
				CommandQueue.pop_front();
				FillBuffer(SendBuffer + (i + 1) * 4, next_byte);
			}
			send(s, (char*)SendBuffer, 28, 0);
			break;

		//-------------case "7" register overwrites----------------------
		case 0x010007:
		case 0x100007:
		case 0x040007:
		{
			FillBuffer(SendBuffer, Command);
			for (int i = 0; i < 6; i++) {	//repeat 6 times incrementing the the buffer accordingly
				int next_byte = CommandQueue.front(); // grab next byte
				CommandQueue.pop_front();

				FillBuffer(SendBuffer + (i + 1) * 4, next_byte);
			}
			send(s, (char*)SendBuffer, 28, 0);
			break;
		}

		//-------------case "9" stop motion cases--------------------
		case 0x200009:
		case 0x080009:
		case 0x020009:
		case 0x040009:
		case 0x100009:
		case 0x3f0009:
			FillBuffer(SendBuffer, Command);
			send(s, (char*)SendBuffer, 4, 0);
			break;


		//------------case 6, speed setting commands----------------------------
		case 0x06:
		case 0x010006:
		case 0x020006:
		case 0x030006:
		case 0x040006:
		case 0x050006:
		case 0x060006:
		case 0x070006:
		case 0x080006:
		case 0x090006:
		case 0x0a0006:
		case 0x0b0006:
			FillBuffer(SendBuffer, Command);
			for (int i = 0; i < 18; i++) {
				int next_byte = CommandQueue.front();
				CommandQueue.pop_front();

				FillBuffer(SendBuffer + (i + 1) * 4, next_byte);
			}
			send(s, (char*)SendBuffer, 76, 0);
			break;

		//--------------------------individualized cases--------------------------------------
		case 0x05: {
			FillBuffer(SendBuffer, 0x05);
			int second_byte = CommandQueue.front();
			CommandQueue.pop_front();
			FillBuffer(SendBuffer + 4, second_byte);
			send(s, (char*)SendBuffer, 8, 0); //send the send buffer
			break;
		}
		case 0x0b: {
			FillBuffer(SendBuffer, 0x0b);
			send(s, (char*)SendBuffer, 4, 0);
			break;
		}
		}
		Sleep(1);
	}
}


//----------------------------------ACCESSIBILITY FUNCTIONS------------------------------------------------
int Initialize() {
	int start_stat;
	start_stat = NetworkStart();
	GracefulStart();
	return start_stat;
}

int SetSpeed(eAxis Axis, int Acceleration, int Desceleration, int MaxSpeed) {
	eAxis ax = Axis;

	double speed = MaxSpeed / 8.3333;
	double acceleration = Acceleration / 16.6666;
	double desceleration = Desceleration / 16.6666;

	speed = speed + 0.5;
	acceleration = acceleration + 0.5;
	desceleration = desceleration + 0.5;

	spd = (int)speed;				//speed now has an integer range of 0 - 12
	accel = (int)acceleration;		//acceleration now has an integer range 0 - 6
	descel = (int)desceleration;	//desceleration now has integer range 0 - 6

	if (spd == 0) spd = 1;
	if (accel == 0) accel = 1;
	if (descel == 0) descel = 1;
	if (spd > 12) return 2;
	if (accel > 6) return 3;
	if (descel > 6) return 4;

	int command;
	int strp_spd;
	int noz_spd;
	int axis_spd;
	int rot_spd;

	switch (spd) {  //build codewords for speed for different functions
	case 1: {
		command = 0x000006;
		strp_spd = 0x03e8;
		noz_spd = 0x01;
		axis_spd = 0x01;
		rot_spd = 0x01f4;
		break;
	}
	case 2: {
		command = 0x010006;
		strp_spd = 0x05dc;
		noz_spd = 0x01f4;
		axis_spd = 0x01f4;
		rot_spd = 0x03e8;
		break;
	}
	case 3: {
		command = 0x020006;
		strp_spd = 0x07d0;
		noz_spd = 0x03e8;
		axis_spd = 0x05dc;
		rot_spd = 0x07d0;
		break;
	}
	case 4: {
		command = 0x030006;
		strp_spd = 0x0bb8;
		noz_spd = 0x07d0;
		axis_spd = 0x09c4;
		rot_spd = 0x0bb8;
		break;
	}
	case 5: {
		command = 0x040006;
		strp_spd = 0x0fa0;
		noz_spd = 0x0bb8;
		axis_spd = 0x1388;
		rot_spd = 0x0fa0;
		break;
	}
	case 6: {
		command = 0x050006;
		strp_spd = 0x1194;
		noz_spd = 0x0fa0;
		axis_spd = 0x2328;
		rot_spd = 0x1388;
		break;
	}
	case 7: {
		command = 0x060006;
		strp_spd = 0x1388;
		noz_spd = 0x1388;
		axis_spd = 0x2ee0;
		rot_spd = 0x1b58;
		break;
	}
	case 8: {
		command = 0x070006;
		strp_spd = 0x1388;
		noz_spd = 0x1b58;
		axis_spd = 0x3a98;
		rot_spd = 0x2328;
		break;
	}
	case 9: {
		command = 0x080006;
		strp_spd = 0x157c;
		noz_spd = 0x2328;
		axis_spd = 0x4268;
		rot_spd = 0x2af8;
		break;
	}
	case 10: {
		command = 0x090006;
		strp_spd = 0x1770;
		noz_spd = 0x2af8;
		axis_spd = 0x4650;
		rot_spd = 0x36b0;
		break;
	}
	case 11: {
		command = 0x0a0006;
		strp_spd = 0x1b58;
		noz_spd = 0x360b;
		axis_spd = 0x4a38;
		rot_spd = 0x4268;
		break;
	}
	case 12: {
		command = 0x0b0006;
		strp_spd = 0x1f40;
		noz_spd = 0x4268;
		axis_spd = 0x4e20;
		rot_spd = 0x4e20;
		break;
	}
	default: {
		command = 0x000006;
		strp_spd = 0x03e8;
		noz_spd = 0x01;
		axis_spd = 0x01;
		rot_spd = 0x01f4;
		return 2;
		break;
	}
	}

	switch (ax) {		//push codewords into variables based on which axis we are modifying
	case AxisX: {
		speed_command = command;
		x_accel = accel;
		x_descel = descel;
		x_speed = axis_spd;
		break;
	}
	case AxisY: {
		speed_command = command;
		y_accel = accel;
		y_descel = descel;
		y_speed = axis_spd;
		break;
	}
	case AxisZ: {
		speed_command = command;
		z_accel = accel;
		z_descel = descel;
		z_speed = noz_spd;
		break;
	}
	case AxisR1: {
		speed_command = command;
		r1_accel = accel;
		r1_descel = descel;
		r1_speed = rot_spd;
		break;
	}
	case AxisR2: {
		speed_command = command;
		r2_accel = accel;
		r2_descel = descel;
		r2_speed = rot_spd;
		break;
	}
	case AxisStrip: {
		speed_command = command;
		strip_accel = accel;
		strip_descel = descel;
		strip_speed = strp_spd;
		break;
	}
	default: {
		return 1;
		break;
	}
	}

	return 0;
}

int CheckLimits() {
	return axis_lim;
}

int CheckStatus() {
	int mask = ((!pres1) << 8) | ((!pres2) << 7) | (blow1 << 6) | (blow2 << 5) | (vac1 << 4) | (vac2 << 3) | ((!pick_lim) << 2) | (strip << 1) | (pump_stat);
	return mask;
}

int CheckButtons() {
	int mask = ((!xpos) << 7) | ((!xneg) << 6) | ((!ypos) << 5) | ((!yneg) << 4) | ((!speed_button) << 3) | ((!step) << 2) | ((!start) << 1) | (!pause);
	return mask;
}

int CheckLED() {
	int mask = ((!run_led) << 4) | ((!pause_led) << 3) | (dot_led << 2) | (con_led << 1) | (cam_led);
	return mask;

}

int SetLED(int led) {
	if ((led & (1 << 4)) >> 4) { //run led on (active low)
		CommandQueue.push_back(0x15);
		CommandQueue.push_back(0x20);
	}
	else { //run led off
		CommandQueue.push_back(0x14);
		CommandQueue.push_back(0x20);
	}
	if ((led & (1 << 3)) >> 3) { //pause led on (active low)
		CommandQueue.push_back(0x15);
		CommandQueue.push_back(0x40);
	}
	else { //pause led off
		CommandQueue.push_back(0x14);
		CommandQueue.push_back(0x40);
	}
	if ((led & (1 << 2)) >> 2) {//dot led on
		CommandQueue.push_back(0x14);
		CommandQueue.push_back(0x0100);
	}
	else { //dot led off
		CommandQueue.push_back(0x15);
		CommandQueue.push_back(0x0100);
	}
	if ((led & (1 << 1)) >> 1) {//con led on
		CommandQueue.push_back(0x14);
		CommandQueue.push_back(0x80);
	}
	else {// con led off
		CommandQueue.push_back(0x15);
		CommandQueue.push_back(0x80);
	}
	if ((led & (1 << 0)) >> 0) {//cam led on
		CommandQueue.push_back(0x14);
		CommandQueue.push_back(0x0200);
	}
	else {//cam led off
		CommandQueue.push_back(0x15);
		CommandQueue.push_back(0x0200);
	}
	return 0;
}

int Poll() {
	ProcessResponse();
	return 0;
}

int PumpOn() {
	CommandQueue.push_back(0x14);
	CommandQueue.push_back(0x0408);
	return 0;
}

int PumpOff() {
	CommandQueue.push_back(0x15);
	CommandQueue.push_back(0x0408);
	return 0;
}

int VacuumOn(int head) {
	if (head) {
		CommandQueue.push_back(0x14);
		CommandQueue.push_back(0x2000);
	}
	else {
		CommandQueue.push_back(0x14);
		CommandQueue.push_back(0x04);
	}
	return 0;
}

int VacuumOff(int head) {
	if (head) {
		CommandQueue.push_back(0x15);
		CommandQueue.push_back(0x2000);
	}
	else {
		CommandQueue.push_back(0x15);
		CommandQueue.push_back(0x04);
	}
	return 0;
}

int BlowOn(int head) {
	if (head) {
		CommandQueue.push_back(0x14);
		CommandQueue.push_back(0x1000);
	}
	else {
		CommandQueue.push_back(0x14);
		CommandQueue.push_back(0x02);
	}
	return 0;
}

int BlowOff(int head) {
	if (head) {
		CommandQueue.push_back(0x15);
		CommandQueue.push_back(0x1000);
	}
	else {
		CommandQueue.push_back(0x15);
		CommandQueue.push_back(0x02);
	}
	return 0;
}

int PickDown() {
	CommandQueue.push_back(0x14);
	CommandQueue.push_back(0x4000);
	return 0;
}

int PickUp() {
	CommandQueue.push_back(0x15);
	CommandQueue.push_back(0x4000);
	return 0;
}

int StripPull() {
	if (strip_pos != 0) return 1;
	else {
		CommandQueue.push_back(0x010008);
		CommandQueue.push_back(0xffe17b80);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
	}
	return 0;
}

int GetXY(int* x, int* y) {
	*x = X_pos;
	*y = Y_pos;
	return 0;
}

int GetA(int head, float* a) {
	if (head) *a = A2_pos;
	else *a = A1_pos;
	return 0;
}

int GetZ(int head, float* z) {
	if (head) *z = -N_pos;
	else *z = N_pos;
	return 0;
}

int StopX() {
	CommandQueue.push_back(0x040009);
	return 0;
}
int StopY() {
	CommandQueue.push_back(0x100009);
	return 0;
}
int StopA(int head) {
	if (head) CommandQueue.push_back(0x200009);
	else CommandQueue.push_back(0x080009);
	return 0;
}
int StopZ() {
	CommandQueue.push_back(0x020009);
	return 0;
}

int MoveA(int head, int a) {
	SendSpeedCommand();
	if (head) {
		CommandQueue.push_back(0x200008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(a);
	}
	else {
		CommandQueue.push_back(0x080008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(a);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
	}
	return 0;
}

int MoveZ(int z) {
	SendSpeedCommand();
	CommandQueue.push_back(0x020008);
	CommandQueue.push_back(0x00);
	CommandQueue.push_back(z);
	CommandQueue.push_back(0x00);
	CommandQueue.push_back(0x00);
	CommandQueue.push_back(0x00);
	CommandQueue.push_back(0x00);
	return 0;
}

int MoveXY(unsigned int x, unsigned int y) {
	SendSpeedCommand();
	
	// why do I see floats here? 
	// never use float for integer arithmetics
	// this is how it should be done
	// Btw, I asked to move any constants into defines - what's 32808? 32808 is the number of steps per 1 meter. 
	// It has to be assignable through the API

	x /= 8; // reduce resolution from 1um to 8um to fit the result into 32 bit
	y /= 8;
	int x_raw = (x * NUM_STEPS + 62) / 125; // 125 * 8 == 1000
	x_raw = 1000 * ((x_raw + 500) / 1000);
	// int x_raw = ((float)x / 1000.00) * 32808.00;
	// x_raw = ToClosestStep(x_raw);
	int y_raw = (y * NUM_STEPS + 62) / 125;
	y_raw = 1000 * ((y_raw + 500) / 100);
	//int y_raw = ((float)y / 1000.00) * 32808.00;
	//y_raw = ToClosestStep(y_raw);


	if ((x != X_pos) && (y == Y_pos)) {
		CommandQueue.push_back(0x040008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(x_raw);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
	}
	if ((x == X_pos) && (y != Y_pos)) {
		CommandQueue.push_back(0x100008);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(0x00);
		CommandQueue.push_back(y_raw);
		CommandQueue.push_back(0x00);
	}
	return 0;
}


int GoHome() {
	if (!homing) {
	//start homing process
		SetSpeed(AxisX, 50, 50, 40);
		SetSpeed(AxisY, 50, 50, 40);

		CommandQueue.push_back(0x3f0009);

		CommandQueue.push_back(0x0b);

		CommandQueue.push_back(0x15);
		CommandQueue.push_back(0x4020);

		CommandQueue.push_back(0x15);
		CommandQueue.push_back(0x742e);

		SendSpeedCommand();

		homing = true;
		return 0;
	}
	else {
		StopX();
		StopY();
		homing = false;
		return 1;
	}
}

bool CheckHome() {
	return homed;
}

std::string GetDebug() {
	return std::string(label_text);
}
