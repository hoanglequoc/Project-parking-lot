#include <iostream>
#include <string>
#include <cstdlib>
#include "Manager.h"

Manager::Manager() {}

Manager::~Manager() 
{
	delete emptyVehicle;
	delete tempCar;
	delete tempMotorbike;
	//delete[] Parkingslot; //not sure if this is needed
}

void Manager::menu()
{
	cout << "Welcome to the self-servicing carpark!" << endl << endl;
	cout << "What can I do for you?" << endl;

	int command = -1;

	do
	{
		cout << "Press 0 to end the program" << endl;
		cout << "Press 1 to add a vehicle" << endl;
		cout << "Press 2 to remove a vehicle" << endl;
		cout << "Press 3 to display all vehicles" << endl;
		cout << "Press 4 to browse for a vehicle" << endl;
		cout << "Press 5 to calculate the parking fee of your vehicle" << endl;
		cin >> command;

		switch (command)
		{
		case 1:
			system("CLS");
			cout << "Adding your vehicle: " << endl;
			addVehicle();
			break;

		case 2:
			system("CLS");
			cout << "Removing your vehicle: " << endl;
			removeVehicle();
			break;

		case 3:
			system("CLS");
			cout << "Displaying all vehicles parked: " << endl;
			display();
			break;

		case 4:
			system("CLS");
			cout << "Finding your vehicle: " << endl;
			browseVehicle();
			break;

		case 5:
			system("CLS");
			cout << "Finding the parking fee of your vehicle: " << endl;
			priceCalculation();
			break;
		}
	} while (command != 0);
}

void Manager::addVehicle()
{
	string tempID;
	int tempDay = 0;
	int tempHour = 0;
	if (Counter <= 0)
	{
		cout << "We're sorry, but the parking lot is full" << endl;
		system("PAUSE");
		system("CLS");
	}
	else
	{
		int vehicleType = 0;
		do
		{
			cout << "\nPlease choose a type of vehicle:" << endl;
			cout << "Press 1 for a car" << endl;
			cout << "Press 2 for a motorbike" << endl;
			cout << "Press 0 to go back to the main menu" << endl;
			
			if (Counter <= 0)
			{
				vehicleType = 0;
			}
			else
			{
				cin >> vehicleType;
			}

			switch (vehicleType)
			{
			case 1:
				bool check1;
				do
				{
					cout << "Enter your car ID: ";
					cin >> tempID;
					if (Counter != 20)
					{
						for (int i = 19; i >= Counter; i--)
						{
							if (tempID == Parkingslot[i]->getID())
							{
								check1 = false;
								cout << "\nYour ID has been registered. Please check and try again." << endl;
								//system("PAUSE");
								break;
							}
							else if (i == Counter)
							{
								check1 = true;
							}
						}
					}
				} while (check1 == false);
				cout << "How many hours are you parking for? ";
				cin >> tempHour;
				cout << "How many days are you parking for? ";
				cin >> tempDay;
				tempCar = new Car(tempHour, tempDay, tempID);
				Parkingslot[Counter - 1] = tempCar;
				Counter--;
				cout << "Free slots left: " << Counter << endl;
				system("PAUSE");
				break;
			case 2:
				bool check2;
				do
				{
					cout << "Enter your motorbike ID: ";
					cin >> tempID;
					if (Counter != 20)
					{
						for (int i = 19; i >= Counter; i--)
						{
							if (tempID == Parkingslot[i]->getID())
							{
								check2 = false;
								cout << "\nYour ID has been registered. Please check and try again." << endl;
								//system("PAUSE");
								break;
							}
							else if (i == Counter)
							{
								check2 = true;
							}
						}
					}
				} while (check2 == false);
				cout << "How many hours are you parking for? ";
				cin >> tempHour;
				cout << "How many days are you parking for? ";
				cin >> tempDay;
				tempMotorbike = new Motorbike(tempHour, tempDay, tempID);
				Parkingslot[Counter - 1] = tempMotorbike;
				Counter--;
				cout << "Free slots left: " << Counter << endl;
				system("PAUSE");
				break;
			}
			system("CLS");
		} while (vehicleType != 0);
		system("CLS");
	}

}

void Manager::removeVehicle()
{
	int command = 0;
	int carsParked = 20 - Counter;
	string pickID;

	if (carsParked > 0)
	{
		do
		{
			cout << "\nPlease select a command:" << endl;
			cout << "Press 1 to remove a vehicle" << endl;
			cout << "Press 0 to go back to the main menu" << endl;
			if (carsParked <= 0 || Counter >=20)
			{
				command = 0;
			}
			else
			{
				cin >> command;
			}

			if (command == 1)
			{
				cout << "Choose the ID of your vehicle among this list:" << endl << endl;
				for (int i = 19; i >= Counter; i--)
				{
					cout << "ID: " << Parkingslot[i]->getID() << endl;
				}
				cin >> pickID;

				for (int i = 19; i >= Counter; i--)
				{
					if (pickID == Parkingslot[i]->getID())
					{
						cout << "\nRemoved vehicle with ID: " << Parkingslot[i]->getID() << endl;
						cout << "Your parking fee is " << Parkingslot[i]->getFee() << "k VND" << endl;
						randLateFee(*Parkingslot[i]);
						cout << "Thank you and have a nice day!" << endl;
						for (int j = i; j >= Counter; j--)
						{
							Parkingslot[j] = Parkingslot[j - 1];
						}
						Parkingslot[Counter] = emptyVehicle;
						Counter++;
						break;
					}
				}
				system("PAUSE");
				system("CLS");
			}
			else
			{
				system("CLS");
			}
		} while (command != 0);
	}
	else
	{
		cout << "\nNo one has parked here." << endl;
		system("PAUSE");
		system("CLS");
	}
}

void Manager::display()
{
	int carsParked = 20 - Counter;
	if (carsParked <= 0)
	{
		cout << "\nThe car park is empty." << endl;
	}
	else
	{
		cout << "\nThis is a list of vehicles parked: " << endl << endl;
		for (int i = 19; i >= Counter; i--)
		{
			Parkingslot[i]->info();
			cout << endl;
		}
		cout << "Free slots left: " << Counter << endl;
	}
	system("PAUSE");
	system("CLS");
}

void Manager::browseVehicle()
{
	int command = 0;
	int carsParked = 20 - Counter;
	string pickID;

	if (carsParked > 0)
	{
		do
		{
			cout << "\nPlease select a command:" << endl;
			cout << "Press 1 to find the information of your vehicle" << endl;
			cout << "Press 0 to go back to the main menu" << endl;
			cin >> command;

			if (command == 1)
			{
				cout << "Choose the ID of your vehicle among this list:" << endl << endl;
				for (int i = 19; i >= Counter; i--)
				{
					cout << "ID: " << Parkingslot[i]->getID() << endl;
				}
				cin >> pickID;

				for (int i = 19; i >= Counter; i--)
				{
					if (pickID == Parkingslot[i]->getID())
					{
						Parkingslot[i]->info();
						cout << "Your vehicle is located in parking slot number " << i + 1 << endl;
						break;
					}
				}
				system("PAUSE");
				system("CLS");
			}
			else
			{
				system("CLS");
			}
		} while (command != 0);
	}
	else
	{
		cout << "\nNo one has parked here." << endl;
		system("PAUSE");
		system("CLS");
	}
}

void Manager::priceCalculation()
{
	int command = 0;
	int carsParked = 20 - Counter;
	string pickID;

	if (carsParked > 0)
	{
		do
		{
			cout << "\nPlease select a command:" << endl;
			cout << "Press 1 to find the fee of your vehicle" << endl;
			cout << "Press 0 to go back to the main menu" << endl;
			cin >> command;

			if (command == 1)
			{
				cout << "Choose the ID of your vehicle among this list:" << endl << endl;
				for (int i = 19; i >= Counter; i--)
				{
					cout << "ID: " << Parkingslot[i]->getID() << endl;
				}
				cin >> pickID;

				for (int i = 19; i >= Counter; i--)
				{
					if (pickID == Parkingslot[i]->getID())
					{
						cout << "Your vehicle is registered for " << Parkingslot[i]->getTime() << " hours" << endl;
						cout << "The fee per hour is " << Parkingslot[i]->getPrice() << "k VND" << endl;
						cout << "Your vehicle's total parking fee is " << Parkingslot[i]->getFee() << "k VND" << endl;
						break;
					}
				}
				system("PAUSE");
				system("CLS");
			}
			else
			{
				system("CLS");
			}
		} while (command != 0);
	}
	else
	{
		cout << "\nNo one has parked here." << endl;
		system("PAUSE");
		system("CLS");
	}
}


void Manager::randLateFee(const Vehicle& vec)
{
	int expectedTime = vec.getTime();
	int actualTime = 0;
	srand(time(0));
	actualTime = rand() % expectedTime * 1.25;
	if (actualTime > expectedTime)
	{
		cout << "\nYou have parked for " << actualTime - expectedTime << " hours too long" << endl;
		cout << "You will be fined " << vec.getPrice() * 10 << "k VND for every additional hour (ten times your hourly rate)" << endl;
		cout << "Your total fee will be " << vec.getFee() + 50 * (actualTime - expectedTime) << "k VND" << endl;
	}
}