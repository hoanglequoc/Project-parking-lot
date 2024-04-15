#pragma once
#include <iostream>
#include "Vehicle.h"

class Motorbike : public Vehicle
{
protected:
	double priceBike = 3;

public:
	Motorbike();
	Motorbike(const int& h, const int& d, const string& ID);
	Motorbike(const Motorbike& mb);
	virtual ~Motorbike();

	virtual double getPrice() const;
	virtual void info() const;
};