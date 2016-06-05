//board.cpp

#include "board-layout.h"

void PCB::set_x(float x) {
	size_x = x;
}

void PCB::set_y(float y){
	size_y = y;
}

void PCB::set_thickness(float t) {
	thick = t;
}

float PCB::x() {
	return size_x;
}

float PCB::y() {
	return size_y;
}

float PCB::thickness() {
	return thick;
}

PCB::PCB(void) {	
};

void FIDUCIAL::FIDUCIAL(void) {

};