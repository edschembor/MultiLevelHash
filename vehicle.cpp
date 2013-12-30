/* Edward Schembor
 * Final Project
 * The implementation of the Vehicle class
 *
 */

#include <iostream>
using std::cout;

#include "vehicle.h"

Vehicle::Vehicle( int idIn, int year, float mileageIn, const string &colorIn )
	:color( colorIn )
{
	setId( idIn );
	setModelYear( year );
	setMileage( mileageIn );
}

void Vehicle::setId( int newId )
{
	id = newId;
}

int Vehicle::getId()
{
	return id;
}

void Vehicle::setModelYear( int year )
{
	if( (year <= 1980) || (year >=2014) )
	{
		cout << "Invalid year. Year set to 2000.\n";
		modelYear = 2000;
	}
	else
		modelYear = year;
}

int Vehicle::getModelYear()
{
	return modelYear;
}

void Vehicle::setMileage( float m)
{
	if( m < 0 )
	{
		cout << "Invalid mileage. Mileage set to 100\n";
		mileage = 100;
	}
	else
		mileage = m;
}

float Vehicle::getMileage()
{
	return mileage;
}

string Vehicle::getColor()
{
	return color;
}

void Vehicle::addTask( Task *task )
{
	Task *pointer;
	
	pointer = &node;

	while( pointer->next != NULL )
		pointer = pointer->next;

	pointer->next = task;

}

//Print is virtual, but not purely virtual, so there is an implementation
void Vehicle::print()
{
	Task *pointer;
	int i;

	pointer = &node;
	i = 1;

	cout << "     Id: " << id << "\n";
	cout << "     Model Year: " << modelYear << "\n";
	cout << "     Mileage: " << mileage << "\n";
	cout << "     Color: " << color << "\n";
	cout << "     Tasks:\n";

	while( pointer->next != NULL )
	{
		cout << "       Task " << i <<":\n";
		pointer->next->printTask();
		pointer = pointer->next;
		i++;
	}

}

float Vehicle::checkout()
{
	Task *pointer1;
	Task *pointer2;
	float total;

	total = 0;
	
	//Is there a more efficient way???
	while( node.next != NULL )
	{
		pointer1 = &node;
		while( pointer1->next != NULL )
		{
			pointer2 = pointer1->next;
			if(  pointer2->next == NULL )
			{
				total += pointer2->getParts();
				total += pointer2->getLabor();
			//	delete &pointer2;
				pointer1->next = NULL;
			}
			if( pointer1->next != NULL)
				pointer1 = pointer1->next;
		}
	}

	return total;
}


ostream& operator << (ostream &out,  Vehicle &v)
{
	v.print();
	return out;
}
