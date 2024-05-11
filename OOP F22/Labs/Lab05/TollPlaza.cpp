#include"TollPlaza.h"

const int TollPlaza::_CAR = 1;
const int TollPlaza::_carToll = 20;
const int TollPlaza::_BIKE = 2;
const int TollPlaza::_bikeToll = 10;
const int TollPlaza::_BUS = 3;
const int TollPlaza::_busToll = 50;
const int TollPlaza::_HEAVY_DUTY_TRUCK = 4;
const int TollPlaza::_heavyDutyTruckToll = 100;
const int TollPlaza::_LIGHT_DUTY_TRUCK = 5;
const int TollPlaza::_lightDutyTruckToll = 70;

TollPlaza::TollPlaza(int id, String adr, long int mt):address (adr)
{
	tollPlazaId = (id >= 0 ? id : 0);
	MAX_TOLL = (mt >= 0 ? mt : 0);
}

void TollPlaza::resetTollPlaza()
{
	tollPlazaId = 0;
	address;
	MAX_TOLL = 0;
	collectedToll = 0;
}

void TollPlaza::chargeVehicle(int vehicleType)
{
	switch (vehicleType)
	{
		case 1:
		{
			collectedToll += _carToll;
			break;
		}
		case 2:
		{
			collectedToll += _bikeToll;
			break;
		}
		case 3:
		{
			collectedToll += _busToll;
			break;
		}
		case 4:
		{
			collectedToll += _heavyDutyTruckToll;
			break;
		}
		case 5:
		{
			collectedToll += _lightDutyTruckToll;
			break;
		}
		default:
			break;
	}
}

long int TollPlaza::getCollectedTollToday() const
{
	return 0;
}

long int TollPlaza::getMaxToll() const
{
	return MAX_TOLL;
}