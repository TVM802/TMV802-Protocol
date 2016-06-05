#include <string>

// HAL API

// returns 0 if ok.
int Initialize();

//returns 0 if started homing, returns 1 is stopped homing
int GoHome();

//returns true if the machine has been homed
bool CheckHome();

enum eAxis { AxisX, AxisY, AxisZ, AxisR1, AxisR2, AxisStrip};
// A, D, MS are in 1-100 range where 100 is the absolute maximum allowed (so probably corresponds to 120%)
// returns 0 if all good
// returns 1 if axis invalid
// returns 2 if speed invalid
// returns 3 if acceleration invalid
// returns 4 if desceleration invalid
int SetSpeed(eAxis Axis, int Acceleration, int Deceleration, int MaxSpeed);

// returns integer of limits, 1 true
//MSB ......... | Y-, Y+, X-, X+, | LSB
int CheckLimits();

//returns integer of sensors, 1 true
//MSB ......... | Pres1, Pres2, Blow1, Blow2, Vac1, Vac2, Pick, Strip, Pump | LSB
int CheckStatus();

//returns status of specific hardware button, 1 true
//MSB ......... | X+, X-, Y+, Y-, DotMove/ConMove, Step, Start/Stop, Pause/Cont | LSB
int CheckButtons();

//returns integer of LEDs, 1 on
//MSB ......... | Run/Stop, Pause/Cont, DotMove, ConMove, Camera | LSB
int CheckLED();

//accepts integer of LEDs, active high
int SetLED(int led);

//returns recieved buffer formatted in hex
std::string GetDebug();



// all coordinates are specified in microns (1/1000 mm)
int GetXY(int* x, int* y);
int GetZ(int head /* either 0 or 1 */, float* z);
int GetA(int head /* either 0 or 1 */, float* a);

int MoveXY(unsigned int x, unsigned int y);
int MoveZ(int z);
int MoveA(int head /*either 0 or 1*/, int a);

int StopX();
int StopY();
int StopA(int head);
int StopZ();

int PumpOn();
int PumpOff();

int VacuumOn(int head);
int VacuumOff(int head);

int StripPull();

int BlowOn(int head);
int BlowOff(int head);

int PickDown();
int PickUp();

int Poll();
