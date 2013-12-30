/* Edward Schembor
 * Final Project
 * The implementation for the Car class
 *
 */

#include "car.h"
#include <iostream>
using std::cout;

Car::Car( int idIn, int year, float mileageIn, const string &colorIn, int eng, float pollution, const string &gas )
	: Vehicle( idIn, year, mileageIn, colorIn)
{
	setEngineSize( eng );
	setPollutionLevel( pollution );
	gasType = gas;
}

void Car::setEngineSize( int newSize )
{
	if( newSize <= 0 )
	{
		cout << "Invalid Engine Size. Engine Size set to 100\n";
		engineSize = 100;
	}
	else
		engineSize = newSize;
}

int Car::getEngineSize()
{
	return engineSize;
}

void Car::setPollutionLevel( float newPoll )
{
	if( newPoll <= 0 )
	{
		cout << "Invalid Pollution Level. Pollution Level set to 100\n";
		pollutionLevel = 100;
	}
	else
		pollutionLevel = newPoll;
}

float Car::getPollutionLevel()
{
	return pollutionLevel;
}

string Car::getGasType()
{
	return gasType;
}

void Car::print()
{
	cout << "Report: \n";
	Vehicle::print();
	cout << "     Engine Size: " << getEngineSize() << "\n";
	cout << "     Pollution Level: " << getPollutionLevel() << "\n";
	cout << "     Gas Type: " << getGasType() << "\n";
}
