/* Edward Schembor
 * Final Project
 * The implementation for the Hybrid class
 *
 */

#include "hybrid.h"
#include <iostream>
using std::cout;

Hybrid::Hybrid( int idIn, int year, float mileageIn, const string &colorIn, int eng, float pollution, const string &gas, float motor, float use, float battery)
	:Car( idIn, year, mileageIn, colorIn, eng, pollution, gas )
{
	setMotorPower( motor );
	setUsage( use );
	setBatteryCapacity( battery );
}

void Hybrid::setMotorPower( float motor )
{
	if( motor <= 0 )
	{
		cout << "Invalid Motor Power. Motor Power set to 100\n";
		motorPower = 100;
	}
	else
		motorPower = motor;
}

float Hybrid::getMotorPower()
{
	return motorPower;
}

void Hybrid::setUsage( float use )
{
	if( use < 0 )
	{
		cout << "Invalid usage. Usage set to 10\n";
		usage = 10;
	}
	else
		usage = use;
}

float Hybrid::getUsage()
{
	return usage;
}

void Hybrid::setBatteryCapacity( float battery )
{
	if( battery <= 0 )
	{
		cout << "Invalid Battery Capacity. Battery Capacity set to 100\n";
		batteryCapacity = 100;
	}
	else
		batteryCapacity = battery;
}

float Hybrid::getBatteryCapacity()
{
	return batteryCapacity;
}

void Hybrid::print()
{
	Car::print();
	cout << "     Motor Power: " << getMotorPower() << "\n";
	cout << "     Usage: " << getUsage() << "\n";
	cout << "     Battery Capacity: " << getBatteryCapacity() << "\n";
}
