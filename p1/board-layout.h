#pragma once
//board.h

class PCB {
	float thick;
	float size_x;
	float size_y;
public:
	void set_x(float x);
	void set_y(float y);
	void set_thickness(float t);
	float x();
	float y();
	float thickness();
	PCB();
};

class FIDUCIAL {
	float x_fed;
	float y_fed;
public:
	void set_x(float x_in);
	void set_y(float y_in);
	float x();
	float y();
	FIDUCIAL();
};