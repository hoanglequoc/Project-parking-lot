#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Motorbike.h"

using namespace std;

Motorbike::Motorbike()
{
	time = 0;
	plateID = "NO PLATE";
	Fee = 0;
}

Motorbike::Motorbike(const int& h, const int& d, const string& ID)
{
	time = h + 24 * d;
	plateID = ID;
	Fee = time * priceBike;
}

Motorbike::Motorbike(const Motorbike& mb)
{
	time = mb.getTime();
	plateID = mb.getID();
	Fee = mb.getFee();
}

Motorbike::~Motorbike() {}

double Motorbike::getPrice() const
{
	return priceBike;
}

void Motorbike::info() const
{
	cout << "Your motorbike's ID: " << plateID << endl;
	cout << "Your motorbike's parking time is " << time << " hours." << endl;
}