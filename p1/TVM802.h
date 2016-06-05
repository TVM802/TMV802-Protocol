#pragma once



class TVM802A
{
public:
	TVM802A();
	~TVM802A();
	enum eCoordType {cCamera, cNozzle1, cNozzle2, cPin};
	

	/// <summary>
	/// Only available after calibration data is set
	/// </summary>
	void GotoCoordinatesMM(int X, int Y);
	
	/// <summary>
	/// Select Which reference point is used for setting coordinates
	/// </summary>
	void SelectCoords(eCoordType ActiveCoords);

	/// <summary>
	/// Moving head in relative coordinates
	/// </summary>
	void MoveSteps(int X, int Y);

	void RotateHead(int Head, int r);

	void SetZ(int Head, int z);

	void PinDown();

	void VacuumOn(int Head);
	void ReadPressure(int Head);

	void SetSpeed(int speed);

private:

};

TVM802A::TVM802A()
{
}

TVM802A::~TVM802A()
{
}