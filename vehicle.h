/* Edward Schembor
 * Final Project
 * The .h file for the Vehicle class
 *
 */
#ifndef VEHICLE_H
#define VEHICLE_H


#include "task.h"
#include <string>
#include <iostream>
using std::string;
using std::ostream;

class Vehicle
{

friend ostream& operator << (ostream &out, Vehicle &v);

public:
	Vehicle( int, int, float, const string &);

	void setId( int ); //Sets id
	int getId(); //Returns id

	void setModelYear( int ); //Sets modelYear
	int getModelYear(); //Returns model year

	void setMileage( float ); //Sets mileage
	float getMileage(); //Returns mileage

	string getColor(); //Returns color

	//Note: Color purposely does not have a set function on purpose

	void addTask( Task *task); //Adds a task to a vehicle

	float checkout(); //Deletes taks and gets the total cost of all tasks

	// Virtual print function makes Vehicle and abstract base class
	virtual void print();


private:
	int id;
	int modelYear;
	float mileage;
	string color;
	Task node;
};

#endif
