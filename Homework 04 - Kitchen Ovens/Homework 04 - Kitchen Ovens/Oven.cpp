#include "Oven.h"

Oven::Oven()
    : RoomTemp(72), //Setting roomtemp Variable to 72
      CurrentTemp(72),
      SetTemp(350),
      IsOvenOn(false), //Setting Oven Variable false
      MaxTemp(550),   //Setting Max Temp
      MinTemp(200)   //Setting Min Temp
{
    //Nada here...
}

int Oven::GetCurrentTemperature() const //Gets the Current Temperature
{

    return CurrentTemp;
}

int Oven::GetSetTemperature() const //Gets the Set Temperature
{
    return SetTemp;
}

void Oven::SetSetTemperature(int Temp) //Sets the Temperature
{
    if ((Temp >= MinTemp) && (Temp <= MaxTemp))
    {
        SetTemp = Temp;
    }
}

void Oven::TurnOn(int SetTemperature) //Sets Temperature and turns the oven on
{
    IsOvenOn = true;
    SetSetTemperature(SetTemperature);
}

void Oven::TurnOff() //Turns Oven Off
{
    IsOvenOn = false;
}

bool Oven::IsOn() const //Sees if Oven is on or not
{
    return IsOvenOn;
}

int Oven::GetMinimumTemperature() const //Gets the Min Temperature
{
    return MinTemp;
}

int Oven::GetMaximumTemperature() const //Gets the Max Temperature
{
    return MaxTemp;
}

int Oven::GetRoomTemperature() const //Gets the Room Temperature
{
    return RoomTemp;
}

void Oven::SimulatePassingOfTime(int TimeInMinutes) //Simulates passing of time
{
    if (IsOvenOn == true) //If Oven is on increase Current Temp
    {
        CurrentTemp += (25 * TimeInMinutes);
        if (CurrentTemp > SetTemp)
        {
            CurrentTemp = SetTemp;
        }
    }
    else         //If Oven is off decrease Current Temp
    {
        CurrentTemp -= (15 * TimeInMinutes);
        if (CurrentTemp > RoomTemp)
        {
            CurrentTemp = RoomTemp;
        }
    }
}
    
