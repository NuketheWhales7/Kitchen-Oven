// Homework 04 - Kitchen Ovens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Chris Miller expert beginner programmer

#include <ctime>
#include <iostream>
#include "Oven.h"

void PrintHeader(const Oven& oven)
{
	std::cout << "---------------------------------------------" << std::endl;

	if (oven.IsOn())
	{
		std::cout << "OVEN IS ON...  CURRENTLY AT ";
		std::cout << oven.GetCurrentTemperature() << " AND SET TO ";
		std::cout << oven.GetSetTemperature() << std::endl;
	}
	else
	{
		std::cout << "OVEN IS OFF...  CURRENTLY AT ";
		std::cout << oven.GetCurrentTemperature() << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;
}

int PrintMenuAndGetMenuChoice()
{
	std::cout << "1) Turn oven ON (and change set temperature)" << std::endl;
	std::cout << "2) Turn oven OFF" << std::endl;
	std::cout << "3) Change set temperature" << std::endl;
	std::cout << "4) Simulate the passage of time" << std::endl;
	std::cout << "5) Exit PROGRAM" << std::endl;

	std::cout << "?? ";
	int choice;
	std::cin >> choice;

	while ((choice < 1) || (choice > 5))
	{
		std::cout << "?? ";
		std::cin >> choice;
	}

	return choice;
}

void TurnOn(Oven& oven)
{
	std::cout << "Oven turned ON" << std::endl;
	std::cout << "Set oven to what temperature? [";
	std::cout << oven.GetMinimumTemperature() << " - ";
	std::cout << oven.GetMaximumTemperature() << "]: ";
	int temperature;
	std::cin >> temperature;
	oven.TurnOn(temperature);
}

void TurnOff(Oven& oven)
{
	std::cout << "Oven turned OFF" << std::endl;
	oven.TurnOff();
}

void ChangeSetTemperature(Oven& oven)
{
	std::cout << "Set oven to what temperature? [";
	std::cout << oven.GetMinimumTemperature() << " - ";
	std::cout << oven.GetMaximumTemperature() << "]: ";
	int temperature;
	std::cin >> temperature;
	oven.SetSetTemperature(temperature);
}

void SimulatePassageOfTime(Oven& oven)
{
	std::cout << "Simulate how many minutes of time? ";
	int time;
	std::cin >> time;
	oven.SimulatePassingOfTime(time);
}

int main()
{
	Oven oven;

	int choice;
	do
	{
		PrintHeader(oven);

		choice = PrintMenuAndGetMenuChoice();
		if (choice == 1)
		{
			TurnOn(oven);
		}
		else if (choice == 2)
		{
			TurnOff(oven);
		}
		else if (choice == 3)
		{
			ChangeSetTemperature(oven);
		}
		else if (choice == 4)
		{
			SimulatePassageOfTime(oven);
		}
		std::cout << std::endl;
	} while (choice != 5);

	if (oven.IsOn() == true)
	{
		std::cout << "You're leaving the oven on as you go away?  For shame...";
		std::cout << std::endl << std::endl;
	}

	system("PAUSE");
	return 0;
}