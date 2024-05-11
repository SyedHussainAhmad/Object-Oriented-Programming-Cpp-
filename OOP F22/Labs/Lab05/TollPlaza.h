#ifndef TOLL_PLAZA_H
#define TOLL_PLAZA_H
#include"String.h"

class TollPlaza
{
	static const int _CAR;
	static const int _carToll;
	static const int _BIKE;
	static const int _bikeToll;
	static const int _BUS;
	static const int _busToll;
	static const int _HEAVY_DUTY_TRUCK;
	static const int _heavyDutyTruckToll;
	static const int _LIGHT_DUTY_TRUCK;
	static const int _lightDutyTruckToll;

	long int collectedToll = 0;
	int tollPlazaId;
	String address;
	long int MAX_TOLL;
public:
	TollPlaza(int , String, long int);
	void resetTollPlaza();
	void chargeVehicle(int);
	long int getCollectedTollToday() const;
	long int getMaxToll() const;
};


#endif // !TOLL_PLAZA_H
