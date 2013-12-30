/* Edward Schembor
 * Final Project
 * The implementation of the Motorcycle class
 *
 */

#include "motorcycle.h"
#include <iostream>
using std::cout;

Motorcycle::Motorcycle( int idIn, int year, float mileageIn, const string &colorIn, int engine, float front, float back)
	:Vehicle( idIn, year, mileageIn, colorIn)
{
	setEngineSize( engine );
	setFrontWheel( front );
	setBackWheel( back );
}

void Motorcycle::setEngineSize( int engine )
{
	if( engine <= 0 )
	{
		cout << "Invalid Engine Size. Engine Size set to 100\n";
		engineSize = 100;
	}
	else
		engineSize = engine;
}

int Motorcycle::getEngineSize()
{
	return engineSize;
}

void Motorcycle::setFrontWheel( float front )
{
	if( front <= 0 )
	{
		cout << "Invalid front wheel size. Front size set to 10\n";
		frontWheelSize = 10;
	}
	else
		frontWheelSize = front;
}

float Motorcycle::getFrontWheel()
{
	return frontWheelSize;
}

void Motorcycle::setBackWheel( float back )
{
	if( back <= 0 )
	{
		cout << "Invalid back wheel size. Back size set to 10\n";
		backWheelSize = 10;
	}
	else
		backWheelSize = back;
}

float Motorcycle::getBackWheel()
{
	return backWheelSize;
}

void Motorcycle::print()
{
	cout << "Motorcycle Report:\n";
	Vehicle::print();
	cout << "     Engine Size: " << getEngineSize() << "\n";
	cout << "     Front Wheel Size: " << getFrontWheel() << "\n";
	cout << "     Back Wheel Size: " << getBackWheel() << "\n";
}
