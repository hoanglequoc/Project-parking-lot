#pragma once
#include <iostream>

using namespace std;

class Vehicle
{
protected:
	string plateID;
	int time;
	double Fee;
	
public:
	Vehicle();
	Vehicle(const int& h,const int& d, const string& ID);
	virtual ~Vehicle();

	string getID() const;
	int getTime() const;
	double getFee() const;

	virtual double getPrice() const;
	virtual void info() const;
	
};