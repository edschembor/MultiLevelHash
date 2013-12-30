/* Edward Schembor
 * Final Project
 * The implementation of the Bus class
 *
 */

#include "bus.h"
#include <iostream>
using std::cout;

Bus::Bus( int idIn, int year, float mileageIn, const string &colorIn, int cap)
	:Vehicle( idIn, year, mileageIn, colorIn)
{
	setCapacity( cap );
}

void Bus::setCapacity( int cap )
{
	if( cap <= 0 )
	{
		cout << "Invalid capacity. Capacity set to 10\n";
		capacity = 10;
	}
	else
		capacity = cap;
}

int Bus::getCapacity()
{
	return capacity;
}

void Bus::print()
{
	cout << "Bus Report\n";
	Vehicle::print();
	cout << "     Capacity: " << getCapacity() << "\n";
}
