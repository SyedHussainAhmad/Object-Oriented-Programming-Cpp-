#include"TollPlazaSystem.h"

void TollPlazaSystem::showMenu()
{
	cout << "Welcome to the toll Plaza Application. \n";
	cout << "\tPress 1 to Reset. \n";
	cout << "\tPress 2 to Charge Vehicle. \n";
	cout << "\tPress 3 to Get Collected Toll. \n";
	cout << "\tPress 4 to Get Maximum Target Toll. \n";
	cout << "\tPress Q/q to exit.\n";
	cout << "Enter your option: ";
}

void TollPlazaSystem::getInput(char &ch)
{
	cin >> ch;
}


void TollPlazaSystem::getTollData(int& id, String& ad, long int& mt)
{
	cout << "Enter Toll Id: ";
	cin >> id;
	cout << "Enter toll adress: ";
	cin.ignore();
	ad.input();
	cout << "Enter toll max target amount: ";
	cin >> mt;
}

void TollPlazaSystem::showVehicleTypeMenu()
{
	cout << " Press 1 for Car. \n";
	cout << " Press 2 for Bike. \n";
	cout << " Press 3 for Bus \n";
	cout << " Press 4 for Heavy Duty Truck \n";
	cout << " Press 5 for Light Duty Truck. \n";
	cout << " Enter your option: ";
}


void TollPlazaSystem::performAppOperation(char ch, TollPlaza toll)
{
	switch (ch)
	{
		case '1':
		{
			toll.resetTollPlaza();
			break;
		}
		case '2':
		{
			int vehicleType;
			showVehicleTypeMenu();
			cin >> vehicleType;
			toll.chargeVehicle(vehicleType);
			if (toll.getCollectedTollToday() >= toll.getMaxToll())
			{
				cout << "\nCongrats you have collected today's Target.";
			}

			break;
		}
		case '3':
		{
			cout << "\n" << toll.getCollectedTollToday();
			break;
		}
		case '4':
		{
			cout << "\n" << toll.getMaxToll();
			break;
		}

		default:
			break;
	}
}

void TollPlazaSystem::startApplication()
{
	char ch;
	int id;
	String ad{};
	long int mt;
	getTollData(id,ad,mt);
	TollPlaza toll{id,ad,mt};
	do
	{
		showMenu();
		getInput(ch);
		performAppOperation(ch, toll);
	}
	while (ch!='Q' && ch != 'q');
}
