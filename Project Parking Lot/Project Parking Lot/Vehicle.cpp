#include <iostream>
#include <string>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle()
{
	time = 0;
	plateID = "Empty slot";
	Fee = 0;
}

Vehicle::Vehicle(const int& h, const int& d, const string& ID)
{
	time = h + 24 * d;
	plateID = ID;
	Fee = 0;
}

Vehicle::~Vehicle() {}

string Vehicle::getID() const
{
	return plateID;
}

int Vehicle::getTime() const
{
	return time;
}

double Vehicle::getPrice() const
{
	return 0;
}

void Vehicle::info() const
{
	cout << "This is simply a vehicle." << endl;
}

double Vehicle::getFee() const
{
	return Fee;
}
