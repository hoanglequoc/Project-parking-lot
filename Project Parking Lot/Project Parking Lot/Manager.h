#pragma once
#include "Vehicle.h"
#include "Car.h"
#include "Motorbike.h"
#include <iostream>

class Manager
{
private:
	Vehicle* Parkingslot[20];
	int Counter = 20;
	Car* tempCar = new Car();
	Motorbike* tempMotorbike = new Motorbike();
	Vehicle* emptyVehicle = new Vehicle();
	
public:
	Manager();
	~Manager();

	//a menu and its options/methods
	void menu();
	void priceCalculation();
	void display();
	void addVehicle();
	void removeVehicle();
	void browseVehicle();

	//late fee simulation
	void randLateFee(const Vehicle& vec);
};