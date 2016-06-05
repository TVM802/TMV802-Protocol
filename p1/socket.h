#pragma once
#ifndef Unit1H
#define Unit1H
#endif
//-----------------------------------------------------------------------------------
#include <deque>
#include <winsock2.h>
//-----------------------------------------------------------------------------------
//std::deque<unsigned int> CommandQueue;
//bool SpeedFast = false;
extern bool SpeedFast;
extern std::deque<unsigned int> CommandQueue;

//WSADATA wsa;
extern SOCKET s;
//struct sockaddr_in server;
//-----------------------------------------------------------------------------------
void ProcessResponse();
int NetworkStart();
//int ProcessButton1();
//void ProcessButton2();