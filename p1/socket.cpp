//-----------------code for communications---------------------
//-----------includes------------------------------------------
#include "socket.h"
#include "MyForm.h"
#include <string>
#define _WINSOCK_DEPRECATED_NO_WARNINGS //remove warnings about depricated functions
//--------------------------------------------------------------
//----------declarations----------------------------------------
WSADATA wsa;
SOCKET s;
struct sockaddr_in server;

std::deque<unsigned int> CommandQueue;
bool SpeedFast = false;

static unsigned char RecvBuffer[2000];
static int BufFilled = 0;

std::string label_text = "null";
char text_buffer[33];

const unsigned char ReqStatus[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const unsigned char Req15[8] = { 0x15, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00 };
const unsigned char Req14[8] = { 0x14, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00 };

System::Void p1::MyForm::timer3_tick(System::Object^  sender, System::EventArgs^  e) {
	System::String^ str = gcnew String(label_text.c_str());
	label1->Text = str;
}

//-------------------------------------------------------------
//---------functions-------------------------------------------
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

void ProcessResponse() {
	int Size = recv(s, (char*)RecvBuffer + BufFilled, 2000 - BufFilled, 0);

	if (Size > 0)
		BufFilled += Size;

	while (BufFilled > 2) {

		unsigned int FirstWord = BuildNumber(RecvBuffer, 2);
		switch (FirstWord) {
		case 0x00: {
			if (BufFilled < 44)
				return;
			// Parse Status word
			int SpeedWord = BuildNumber(RecvBuffer + 4, 2);


			if (SpeedWord == 0x2c0) {
				SpeedFast = true;
				//Form1->lSpeed->Caption = "FastSpeed";  //pass variables instead to MyForm to update label
				//label1->Text = "FastSpeed";
				label_text = "FastSpeed";
				
			}
			else if (SpeedWord == 0x340) {
				//Form1->lSpeed->Caption = "LowSpeed";
				SpeedFast = 0;
				label_text = "LowSpeed";
			}
			else
				//Form1->lSpeed->Caption = AnsiString::IntToHex(SpeedWord, 4);
				//label_text = "test";
				//char buffer[4];
				itoa(SpeedWord, text_buffer, 16);
				//label_text = std::to_string(SpeedWord);
				label_text = text_buffer;
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
		case 0x15:
		{
			FillBuffer(SendBuffer, 0x15);
			int SecondByte = CommandQueue.front();
			CommandQueue.pop_front();

			FillBuffer(SendBuffer + 4, SecondByte);

			send(s, (char*)SendBuffer, 8, 0);
			break;
		}
		case 0x14: {
			FillBuffer(SendBuffer, 0x14);
			int SecondByte = CommandQueue.front();
			CommandQueue.pop_front();

			FillBuffer(SendBuffer + 4, SecondByte);

			send(s, (char*)SendBuffer, 8, 0);
			break;
		}
		}
	}
}
/*
int ProcessButton1() {	//used to be in MyForm.cpp. put here to avoid dependancy conflicts
	unsigned char GoLeft1[] = { 0x01, 0x00, 0x00, 0x00, 0xc0, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	unsigned char GoLeft[] = { 0x09, 0x00, 0x04, 0x00 };
	int res = send(s, (const char*)GoLeft, sizeof(GoLeft), 0);
	return res;
}

void ProcessButton2() {	//used to be in MyForm.cpp. put here to avoid dependancy conflicts
	if (SpeedFast) {
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
	SpeedFast = !SpeedFast;
}
*/