#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"

using namespace std;

Car::Car()
{
	time = 0;
	plateID = "NO PLATE";
	Fee = 0;
}

Car::Car(const int& h, const int& d, const string& ID)
{
	time = h + 24 * d;
	plateID = ID;
	Fee = time * priceCar;
}

Car::Car(const Car& c)
{
	time = c.getTime();
	plateID = c.getID();
	Fee = c.getFee();
}

Car::~Car() {}

double Car::getPrice() const
{
	return priceCar;
}

void Car::info() const
{
	cout << "Your car's ID: " << plateID << endl;
	cout << "Your car's parking time is " << time << " hours." << endl;
}