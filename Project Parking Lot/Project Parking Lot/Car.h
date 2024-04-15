#pragma once
#include <iostream>
#include "Vehicle.h"

class Car : public Vehicle
{
protected:
	double priceCar = 5;

public:
	Car();
	Car(const int& h, const int& d, const string& ID);
	Car(const Car& c);
	virtual ~Car();

	virtual double getPrice() const;
	virtual void info() const;
};