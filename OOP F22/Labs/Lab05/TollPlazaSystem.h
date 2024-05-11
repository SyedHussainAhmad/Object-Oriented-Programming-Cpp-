#ifndef TOLL_PLAZA_SYSTEM
#define TOLL_PLAZA_SYSTEM

#include"TollPlaza.h"
#include<iostream>
using namespace std;

class TollPlazaSystem
{
	static void showMenu();
	static void getInput(char&);
	static void performAppOperation(char, TollPlaza);
	static void getTollData(int&, String&, long int &);
	static void showVehicleTypeMenu();
public:
	static void startApplication();
};
#endif // !TOLL_PLAZA_SYSTEM
