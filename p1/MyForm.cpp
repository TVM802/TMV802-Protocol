
#include "MyForm.h"
#include "FileBrowse.h"
//#include "socket.h"
//#include "opencv2/opencv.hpp"
#include <deque>
#include <winsock2.h>
#include <string>
#include <sstream>
#include <math.h>
#include <cmath>
#include "pugixml.hpp"
#include "hal-api.h"

using namespace System;
using namespace System::Windows::Forms;
//using namespace cv;
//[STATThread]

void ocv_camera() {
}

//declarations-------------------------------------------------------------------
const char* WindowName = "OpenCV";
int lowThreshold;
int highThreshold;
bool start_delay = true;

//system methods-----------------------------------------------------------------

System::Void p1::MyForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	// return;
	/*
	static int Initialized = 0;
	static Mat* frame = 0;

	static VideoCapture* cap = 0;
	if (!Initialized) {
		cap = new VideoCapture();
		frame = new Mat();
		if (!cap->open(0))
			return;
		Initialized = 1;
		namedWindow(WindowName, CV_WINDOW_AUTOSIZE);
	}

	lowThreshold = tbThreshold->Value;
	highThreshold = tbThreshold2->Value;


	// open the default camera, use something different from 0 otherwise;
	// Check VideoCapture documentation.
	

	
	//waitKey(1);
	
	if ( cbCapture->Checked )
		(*cap) >> *frame;
	if (frame->empty())
		return; // end of video stream
	
	cv::Mat gray;
	cv::cvtColor(*frame, gray, CV_BGR2GRAY);
	// Convert to binary image using Canny
	cv::Mat bw = gray;
	cv::Mat bw2;
	//cv::fastNlMeansDenoising(gray, bw, 3, 3, 3);
	cv::Canny(bw, bw2, lowThreshold, highThreshold);

	// Find contours
	std::vector<std::vector<cv::Point> > contours;
	
	cv::findContours(bw2, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

	// The array for storing the approximation curve
	std::vector<cv::Point> approx;

	// We'll put the labels in this destination image
	//cv::Mat dst = src.clone();

	Mat FrameCopy = frame->clone();

	for (int i = 0; i < contours.size(); i++) {
		// Approximate contour with accuracy proportional
		// to the contour perimeter
		cv::approxPolyDP(
			cv::Mat(contours[i]),
			approx,
			cv::arcLength(cv::Mat(contours[i]), true) * 0.02,
			true
			);

		// Skip small or non-convex objects 
		if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(approx))
			continue;
		int AprSize = approx.size();
		if (AprSize >= 4 || AprSize <= 10 ) {
			for (int i = 0; i < approx.size(); i++) {
				line(FrameCopy, approx[i], approx[(i+1) % AprSize], 0x00FFFF, 1);
			}
		}
			
	}

	line(FrameCopy, cv::Point(frame->cols / 2, 0), cv::Point(frame->cols / 2, frame->rows - 1), 0xff00ff, 1);
	line(FrameCopy, cv::Point(0, frame->rows / 2), cv::Point(frame->cols-1, frame->rows/2), 0xff00ff, 1);
	imshow(WindowName, FrameCopy);
	imshow("Canny", bw2);
	// the camera will be closed automatically upon exit
//	cap->release();
//	delete cap;

//	cvtColor(matImage, matImage, CV_BGRA2RGBA);
//
//	hBitmap = CreateBitmap(matImage.cols, matImage.rows, 1, 32, matImage.data);
	*/
}
//this is the timer that rruns the cameras, commented out for now
System::Void p1::MyForm::timer2_tick(System::Object^  sender, System::EventArgs^  e) {

	Poll();

	int limits = CheckLimits();
	if (limits & 1) label_xpos->BackColor = Color::Red;
	else label_xpos->BackColor = Color::LightGray;
	if ((limits & (1 << 1)) >> 1) label_xneg->BackColor = Color::Red;
	else label_xneg->BackColor = Color::LightGray;
	if ((limits & (1 << 2)) >> 2) label_ypos->BackColor = Color::Red;
	else label_ypos->BackColor = Color::LightGray;
	if ((limits & (1 << 3)) >> 3) label_yneg->BackColor = Color::Red;
	else label_yneg->BackColor = Color::LightGray;

	int status = CheckStatus();
	if ((status & (1 << 8)) >> 8) Pres1->BackColor = Color::LightGreen;
	else Pres1->BackColor = Color::LightGray;
	if ((status & (1 << 7)) >> 7) Pres2->BackColor = Color::LightGreen;
	else Pres2->BackColor = Color::LightGray;
	if ((status & (1 << 6)) >> 6) Blow1->BackColor = Color::LightGreen;
	else Blow1->BackColor = Color::LightGray;
	if ((status & (1 << 5)) >> 5) Blow2->BackColor = Color::LightGreen;
	else Blow2->BackColor = Color::LightGray;
	if ((status & (1 << 4)) >> 4) Vac1->BackColor = Color::LightGreen;
	else Vac1->BackColor = Color::LightGray;
	if ((status & (1 << 3)) >> 3) Vac2->BackColor = Color::LightGreen;
	else Vac2->BackColor = Color::LightGray;
	if ((status & (1 << 2)) >> 2) Pick->BackColor = Color::LightGreen;
	else Pick->BackColor = Color::LightGray;
	if ((status & (1 << 1)) >> 1) Strip->BackColor = Color::LightGreen;
	else Strip->BackColor = Color::LightGray;

	int LED = CheckLED();
	int dotmove = ((LED & (1 << 2)) >> 2);
	if (dotmove) button_speed->Text = "Slow Speed";
	else button_speed->Text = "Fast Speed";
	label2->Text = Convert::ToString(LED);
	
	int x;
	int y;
	float a;
	float z;
	GetXY(&x, &y);
	X_coord->Text = "X: " + Convert::ToString(round(((float)x / 1000.0) * 100) / 100);
	Y_coord->Text = "Y: " + Convert::ToString(round(((float)y / 1000.0) * 100) / 100);
	GetA(0, &a);
	A1_rot->Text = "A1: " + Convert::ToString(a);
	GetA(1, &a);
	A2_rot->Text = "A2: " + Convert::ToString(a);
	GetZ(0, &z);
	if (z > 0) z = 0;
	Z1->Text = "Z1: " + Convert::ToString(z);
	GetZ(1, &z);
	if (z > 0) z = 0;
	Z2->Text = "Z2: " + Convert::ToString(z);

	static int buttons_old = 0;
	int buttons = CheckButtons();
	if (((buttons & (1 << 7)) >> 7) && !((buttons_old & (1 << 7)) >> 7)) { //detects hardware button pressed down
		button_xpos->BackColor = Color::Gray;
		if (dotmove) SetSpeed(AxisX, 70, 70, 0);
		else SetSpeed(AxisX, 70, 70, 30);
		MoveXY(0x01f49c40, y);
	}
	else if (!((buttons & (1 << 7)) >> 7) && ((buttons_old & (1 << 7)) >> 7)) { //detects hw button release
		button_xpos->BackColor = Color::LightGray;
		StopX();
	}
	if (((buttons & (1 << 6)) >> 6) && !((buttons_old & (1 << 6)) >> 6)) {
		button_xneg->BackColor = Color::Gray;
		if (dotmove) SetSpeed(AxisX, 70, 70, 0);
		else SetSpeed(AxisX, 70, 70, 30);
		MoveXY(0xfe0b63c0, y);
	}
	else if (!((buttons & (1 << 6)) >> 6) && ((buttons_old & (1 << 6)) >> 6)) {
		button_xneg->BackColor = Color::LightGray;
		StopX();
	}
	if (((buttons & (1 << 5)) >> 5) && !((buttons_old & (1 << 5)) >> 5)) {
		button_ypos->BackColor = Color::Gray;
		if (dotmove) SetSpeed(AxisY, 70, 70, 0);
		else SetSpeed(AxisY, 70, 70, 30);
		MoveXY(x, 0x01f49c40);
	}
	else if (!((buttons & (1 << 5)) >> 5) && ((buttons_old & (1 << 5)) >> 5)) {
		button_ypos->BackColor = Color::LightGray;
		StopY();
	}
	if (((buttons & (1 << 4)) >> 4) && !((buttons_old & (1 << 4)) >> 4)) {
		button_yneg->BackColor = Color::Gray;
		if (dotmove) SetSpeed(AxisY, 70, 70, 0);
		else SetSpeed(AxisY, 70, 70, 30);
		MoveXY(x, 0xfe0b63c0);
	}
	else if (!((buttons & (1 << 4)) >> 4) && ((buttons_old & (1 << 4)) >> 4)) {
		button_yneg->BackColor = Color::LightGray;
		StopY();
	}
	if ((buttons & (1 << 1)) >> 1) Run->BackColor = Color::Gray;
	else Run->BackColor = Color::LightGray;
	if ((buttons & (1 << 2)) >> 2) Step->BackColor = Color::Gray;
	else Step->BackColor = Color::LightGray;
	if ((buttons & (1 << 0)) >> 0) Pause->BackColor = Color::Gray;
	else Pause->BackColor = Color::LightGray;
	buttons_old = CheckButtons();




	std::string debug = GetDebug();
	System::String^ str = gcnew System::String(debug.c_str());
	label1->Text = str;

	if (CheckHome())
		button_Move->Enabled = true;

}

System::Void p1::MyForm::timer3_tick(System::Object^  sender, System::EventArgs^  e) {

}

System::Void p1::MyForm::bLoadFile_Click(System::Object^  sender, System::EventArgs^  e) {

	/*System::String^ FileName = Browse_File->FileName;
	if (Browse_File->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		//System::String^ FileName = Browse_File->FileName;
		System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(Browse_File->FileName);
		MessageBox::Show(sr->ReadToEnd());
		sr->Close();
	}*/
	//testing the pcb class
	// cant figure out how to get the feducials





	//above is "testing code", testing operation of the file dialogue selection. it works just annoying to pop up all the time so commented out

	std::string test;
	std::string test2;
	int test_flag = 0;
	std::string test3 = "test";
	std::string test4 = "test";
	pugi::xml_document doc;
	if (!doc.load_file("compList.xml")) {			//filename hardcoded for now, can grab from dialogue selection later. Its included in resource files under solution
		Sleep(10); //error
	}
	pugi::xml_node info = doc.child("PCBInfo");
	test = info.name();								//this correctly returns the name of the parent node PCBInfo

	for (pugi::xml_node item = info.first_child(); item; item = item.next_sibling()) {		//for every child of PCBInfo
		//here we can guarantee we have a new element from pcb info NEW TIER 1 ITEM
		test = item.name();							//name of TIER 1 item						
		pugi::xml_node sub_item = item.first_child();
		pugi::xml_node sub_sub_item = sub_item.first_child();
		if (!sub_sub_item.empty()) {
			//here we can guarantee we have a new feducial NEW TIER 2 ITEM
			for (pugi::xml_node sub_item = item.first_child(); sub_item; sub_item = sub_item.next_sibling()) {	//for every child of that child
				test3 = sub_item.name();					//name of first child of feducial (coordinate label) name of TIER 2 item
				test4 = sub_item.child_value();				//value of first child of feducial (coordinate value) value of TIER 2 item
			}
		}
		else {
			test2 = sub_item.value();  //value of TIER 1 item
		}
	}



	
	//pugi::xml_parse_result result = doc.load_file("compList.xml", pugi::parse_default, pugi::encoding_utf8);		//why wont this open the file?!?!?!?!?!

}

System::Void p1::MyForm::button1_click(System::Object^ sender, System::EventArgs^ e) {
	/*unsigned char GoLeft1[] = { 0x01, 0x00, 0x00, 0x00, 0xc0, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	unsigned char GoLeft[] = { 0x09, 0x00, 0x04, 0x00 };
	int res = send(s, (const char*)GoLeft, sizeof(GoLeft), 0); // send function and s in socket.h
	//int res = ProcessButton1(); //see socket.cpp*/
}

System::Void p1::MyForm::button_speed_click(System::Object^ sender, System::EventArgs^ e) {
	int led = CheckLED();
	int dotmove = ((led & (1 << 2)) >> 2);
	int conmove = ((led & (1 << 1)) >> 1);
	led = led & 0b11001; //clear those two locations in vector in prep for new or.
	led = led | ((!dotmove) << 2) | ((!conmove) << 1);
	SetLED(led);
}

System::Void p1::MyForm::Pump_click(System::Object^  sender, System::EventArgs^  e) {
	if (CheckStatus() & 1) {
		PumpOff();
	}
	else { 
		PumpOn();
	}
}

System::Void p1::MyForm::Pick_click(System::Object^ sender, System::EventArgs^ e) {
	if ((CheckStatus() & (1 << 2)) >> 2) {
		PickUp();
		button_pick->BackColor = Color::LightGray;
	}
	else {
		PickDown();
		button_pick->BackColor = Color::Gray;
	}
}

System::Void p1::MyForm::Vac1_click(System::Object^ sender, System::EventArgs^ e) {
	if ((CheckStatus() & (1 << 4)) >> 4) {
		VacuumOff(0);
	}
	else {
		VacuumOn(0);
	}
}

System::Void p1::MyForm::Vac2_click(System::Object^ sender, System::EventArgs^ e) {
	if ((CheckStatus() & (1 << 3)) >> 3) {
		VacuumOff(1);
	}
	else {
		VacuumOn(1);
	}
}

System::Void p1::MyForm::Blow1_click(System::Object^ sender, System::EventArgs^e) {
	if ((CheckStatus() & (1 << 6)) >> 6) {
		BlowOff(0);
		button_blow1->BackColor = Color::LightGray;
	}
	else {
		BlowOn(0);
		button_blow1->BackColor = Color::Gray;
	}
}

System::Void p1::MyForm::Blow2_click(System::Object^ sender, System::EventArgs^e) {
	if ((CheckStatus() & (1 << 5)) >> 5) {
		BlowOff(1);
		button_blow2->BackColor = Color::LightGray;
	}
	else {
		BlowOn(1);
		button_blow2->BackColor = Color::Gray;
	}
}

System::Void p1::MyForm::Strip_press(System::Object^ sender, System::EventArgs^ e) {
	StripPull();
}

//A1+ button is pressed down
System::Void p1::MyForm::A1pos_mouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e) {
	button_a1_pos->BackColor = Color::Gray;
	SetSpeed(AxisR1, 30, 30, 30);
	MoveA(0, 0x186a00);
}
//A1+ button is released
System::Void p1::MyForm::A1pos_click(System::Object ^ sender, System::EventArgs ^ e) {
	button_a1_pos->BackColor = Color::LightGray;
	StopA(0);
}
//A1- button is pressed down
System::Void p1::MyForm::A1neg_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	button_a1_neg->BackColor = Color::Gray;
	SetSpeed(AxisR1, 30, 30, 30);
	MoveA(0, 0x00);
}
//A1- button is released
System::Void p1::MyForm::A1neg_click(System::Object^ sender, System::EventArgs ^ e) {
	button_a1_neg->BackColor = Color::LightGray;
	StopA(0);
}

//A2+ button is pressed down
System::Void p1::MyForm::A2pos_mouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e) {
	button_a2_pos->BackColor = Color::Gray;
	SetSpeed(AxisR2, 30, 30, 30);
	MoveA(1, 0x186a00);
}
//A2+ button is released
System::Void p1::MyForm::A2pos_click(System::Object ^ sender, System::EventArgs ^ e) {
	button_a2_pos->BackColor = Color::LightGray;
	StopA(1);
}
//A2- button is pressed down
System::Void p1::MyForm::A2neg_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	button_a2_neg->BackColor = Color::Gray;
	SetSpeed(AxisR1, 30, 30, 30);
	MoveA(1, 0x00);
}
//A2- button is released
System::Void p1::MyForm::A2neg_click(System::Object^ sender, System::EventArgs ^ e) {
	button_a2_neg->BackColor = Color::LightGray;
	StopA(1);
}

//N1 Up button pressed down
System::Void p1::MyForm::N1_up_mouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs^e) {
	button_n1up->BackColor = Color::Gray;
	SetSpeed(AxisZ, 30, 30, 30);
	MoveZ(0x00);
}
//N1 Up button is released
System::Void p1::MyForm::N1_up_click(System::Object^ sender, System::EventArgs^e) {
	button_n1up->BackColor = Color::LightGray;
	StopZ();
}
//N1 down button pressed down
System::Void p1::MyForm::N1_dwn_mouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs^e) {
	button_n1dw->BackColor = Color::Gray;
	SetSpeed(AxisZ, 30, 30, 30);
	MoveZ(0xfffb3d40);
}
//N1 down button is released
System::Void p1::MyForm::N1_dwn_click(System::Object^ sender, System::EventArgs^e) {
	button_n1dw->BackColor = Color::LightGray;
	StopZ();
}

//N2 Up button pressed down
System::Void p1::MyForm::N2_up_mouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs^e) {
	button_n2up->BackColor = Color::Gray;
	SetSpeed(AxisZ, 30, 30, 30);
	MoveZ(0x00);
}
//N2 Up button is released
System::Void p1::MyForm::N2_up_click(System::Object^ sender, System::EventArgs^e) {
	button_n2up->BackColor = Color::LightGray;
	StopZ();
}
//N2 down button pressed down
System::Void p1::MyForm::N2_dwn_mouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs^e) {
	button_n2dw->BackColor = Color::Gray;
	SetSpeed(AxisZ, 30, 30, 30);
	MoveZ(0x04c2c0);
}
//N2 down button is released
System::Void p1::MyForm::N2_dwn_click(System::Object^ sender, System::EventArgs^e) {
	button_n2dw->BackColor = Color::LightGray;
	StopZ();
}

//X- is pressed down
System::Void p1::MyForm::Xneg_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if ((CheckLED() & (1 << 2)) >> 2) SetSpeed(AxisX, 70, 70, 0);
	else SetSpeed(AxisX, 70, 70, 30);
	int x;
	int y;
	GetXY(&x, &y);
	MoveXY(0xfe0b63c0, y);
}
//X- is released
System::Void p1::MyForm::Xneg_click(System::Object^ sender, System::EventArgs^e) {
	StopX();
}
//X+ is pressed down
System::Void p1::MyForm::Xpos_mouseDown(System::Object^sender, System::Windows::Forms::MouseEventArgs^e) {
	if ((CheckLED() & (1 << 2)) >> 2) SetSpeed(AxisX, 70, 70, 0);
	else SetSpeed(AxisX, 70, 70, 30);
	int x;
	int y;
	GetXY(&x, &y);
	MoveXY(0x01f49c40, y);
}
//X+ is released
System::Void p1::MyForm::Xpos_click(System::Object^ sender, System::EventArgs^e) {
	StopX();
}

//Y- is pressed down
System::Void p1::MyForm::Yneg_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if ((CheckLED() & (1 << 2)) >> 2) SetSpeed(AxisY, 70, 70, 0);
	else SetSpeed(AxisY, 70, 70, 30);
	int x;
	int y;
	GetXY(&x, &y);
	MoveXY(x, 0xfe0b63c0);
}
//Y- is released
System::Void p1::MyForm::Yneg_click(System::Object^ sender, System::EventArgs^e) {
	StopY();
}
//Y+ is pressed down
System::Void p1::MyForm::Ypos_mouseDown(System::Object^sender, System::Windows::Forms::MouseEventArgs^e) {
	if ((CheckLED() & (1 << 2)) >> 2) SetSpeed(AxisY, 70, 70, 0);
	else SetSpeed(AxisY, 70, 70, 30);
	int x;
	int y;
	GetXY(&x, &y);
	MoveXY(x, 0x01f49c40);
}
//Y+ is released
System::Void p1::MyForm::Ypos_click(System::Object^ sender, System::EventArgs^e) {
	StopY();
}


//Speed scroll bar changes
System::Void p1::MyForm::SpeedChange(System::Object^ sender, System::EventArgs^e) {
	int value = (SpeedBar->Value);
	SpeedLabel->Text = "Speed: " + Convert::ToString(value) + "%";
}

System::Void p1::MyForm::AccelChange(System::Object^ sender, System::EventArgs^e) {
	int value = AccelBar->Value;
	AccelLabel->Text = "Acceleration: " + Convert::ToString(value) + "%";
}

System::Void p1::MyForm::DescelChange(System::Object^ sender, System::EventArgs^e) {
	int value = DescelBar->Value;
	DescelLabel->Text = "Desceleration: " + Convert::ToString(value) + "%";
}

System::Void p1::MyForm::Home_click(System::Object^ sender, System::EventArgs^e) {
	GoHome();
}

System::Void p1::MyForm::Move_click(System::Object^ sender, System::EventArgs^e) {
	button_vac1->Enabled = false;
	button_vac1->Visible = false;
	button_vac2->Enabled = false;
	button_vac2->Visible = false;
	button_blow1->Enabled = false;
	button_blow1->Visible = false;
	button_blow2->Enabled = false;
	button_blow2->Visible = false;
	button_pump->Enabled = false;
	button_pump->Visible = false;
	button_pick->Visible = false;
	button_pick->Enabled = false;
	button_strip->Enabled = false;
	button_strip->Visible = false;
	button_a1_pos->Visible = false;
	button_a1_pos->Enabled = false;
	button_a1_neg->Enabled = false;
	button_a1_neg->Visible = false;
	button_a2_pos->Visible = false;
	button_a2_pos->Enabled= false;
	button_a2_neg->Enabled = false;
	button_a2_neg->Visible = false;
	button_speed->Visible = false;
	button_speed->Enabled = false;
	button_n1up->Visible = false;
	button_n1up->Enabled = false;
	button_n1dw->Visible = false;
	button_n1dw->Enabled = false;
	button_n2up->Visible = false;
	button_n2up->Enabled = false;
	button_n2dw->Visible = false;
	button_n2dw->Enabled = false;
	button_ypos->Visible = false;
	button_ypos->Enabled = false;
	button_yneg->Visible = false;
	button_yneg->Enabled = false;
	button_xpos->Visible = false;
	button_xpos->Enabled = false;
	button_xneg->Visible = false;
	button_xneg->Enabled = false;

	SpeedBar->Visible = true;
	SpeedBar->Enabled = true;
	AccelBar->Visible = true;
	AccelBar->Enabled = true;
	DescelBar->Visible = true;
	DescelBar->Enabled = true;
	SpeedLabel->Visible = true;
	AccelLabel->Visible = true;
	DescelLabel->Visible = true;

	X_box->Visible = true;
	X_box->Enabled = true;
	Y_box->Visible = true;
	Y_box->Enabled = true;
	X_go->Visible = true;
	X_go->Enabled = true;
	X_stop->Visible = true;
	X_stop->Enabled = true;
	Y_go->Visible = true;
	Y_go->Enabled = true;
	Y_stop->Visible = true;
	Y_stop->Enabled = true;
	X_label->Visible = true;
	Y_label->Visible = true;

	/*CommandQueue.push_back(0x0b);

	CommandQueue.push_back(0x15);
	CommandQueue.push_back(0x4020);

	CommandQueue.push_back(0x15);
	CommandQueue.push_back(0x20);*/
}

System::Void p1::MyForm::Manual_click(System::Object^sender, System::EventArgs^e) {
	button_vac1->Enabled = true;
	button_vac1->Visible = true;
	button_vac2->Enabled = true;
	button_vac2->Visible = true;
	button_blow1->Enabled = true;
	button_blow1->Visible = true;
	button_blow2->Enabled = true;
	button_blow2->Visible = true;
	button_pump->Enabled = true;
	button_pump->Visible = true;
	button_pick->Visible = true;
	button_pick->Enabled = true;
	button_strip->Enabled = true;
	button_strip->Visible = true;
	button_a1_pos->Visible = true;
	button_a1_pos->Enabled = true;
	button_a1_neg->Enabled = true;
	button_a1_neg->Visible = true;
	button_a2_pos->Visible = true;
	button_a2_pos->Enabled = true;
	button_a2_neg->Enabled = true;
	button_a2_neg->Visible = true;
	button_speed->Visible = true;
	button_speed->Enabled = true;
	button_n1up->Visible = true;
	button_n1up->Enabled = true;
	button_n1dw->Visible = true;
	button_n1dw->Enabled = true;
	button_n2up->Visible = true;
	button_n2up->Enabled = true;
	button_n2dw->Visible = true;
	button_n2dw->Enabled = true;
	button_ypos->Visible = true;
	button_ypos->Enabled = true;
	button_yneg->Visible = true;
	button_yneg->Enabled = true;
	button_xpos->Visible = true;
	button_xpos->Enabled = true;
	button_xneg->Visible = true;
	button_xneg->Enabled = true;

	SpeedBar->Visible = false;
	SpeedBar->Enabled = false;
	AccelBar->Visible = false;
	AccelBar->Enabled = false;
	DescelBar->Visible = false;
	DescelBar->Enabled = false;
	SpeedLabel->Visible = false;
	AccelLabel->Visible = false;
	DescelLabel->Visible = false;

	X_box->Visible = false;
	X_box->Enabled = false;
	Y_box->Visible = false;
	Y_box->Enabled = false;
	X_go->Visible = false;
	X_go->Enabled = false;
	X_stop->Visible = false;
	X_stop->Enabled = false;
	Y_go->Visible = false;
	Y_go->Enabled = false;
	Y_stop->Visible = false;
	Y_stop->Enabled = false;
	X_label->Visible = false;
	Y_label->Visible = false;

	/*CommandQueue.push_back(0x0b);

	CommandQueue.push_back(0x15);
	CommandQueue.push_back(0x4020);

	CommandQueue.push_back(0x15);
	CommandQueue.push_back(0x20);*/
}

System::Void p1::MyForm::X_go_Click(System::Object^sender, System::EventArgs^e) {
	System::String^ buffer;
	buffer = X_box->Text;
	float X_target = (float)(Convert::ToDouble(buffer));
	int X_target_raw = X_target * 1000.00; //multiply by a thousand to get target in microns
	SetSpeed(AxisX, AccelBar->Value, DescelBar->Value, SpeedBar->Value); //user defined movement
	int x;
	int y;
	GetXY(&x, &y);
	MoveXY(X_target_raw, y);
}

System::Void p1::MyForm::Y_go_Click(System::Object^sender, System::EventArgs^e) {
	System::String^ buffer;
	buffer = Y_box->Text;
	float Y_target = (float)(Convert::ToDouble(buffer));
	int Y_target_raw = Y_target * 1000.00;
	SetSpeed(AxisY, AccelBar->Value, DescelBar->Value, SpeedBar->Value); //user defined movement
	int x;
	int y;
	GetXY(&x, &y);
	MoveXY(x, Y_target_raw);
}




//int main(Platform::Array<Platform::String> args) {
[System::STAThread]
void Main(array<System::String^>^ args) {
	//ocv_camera();		//disable cameras

	//Initialize();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	p1::MyForm form;
	Application::Run(%form);

}
