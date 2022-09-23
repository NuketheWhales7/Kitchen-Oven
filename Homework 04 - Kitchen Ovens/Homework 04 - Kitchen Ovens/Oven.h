#pragma once
//Oven Header
class Oven
{
public:
	Oven();
	int GetCurrentTemperature() const;
	int GetSetTemperature() const;
	void SetSetTemperature(int Temp);
	void TurnOn(int SetTemperature = 350);
	void TurnOff();
	bool IsOn() const;
	int GetMinimumTemperature() const;
	int GetMaximumTemperature() const;
	int GetRoomTemperature() const;
	void SimulatePassingOfTime(int TimeInMinutes);

private:
	int CurrentTemp;
	int SetTemp;
	int RoomTemp;
	bool IsOvenOn;
	int MaxTemp;
	int MinTemp;
};