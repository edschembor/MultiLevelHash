/* Edward Schembor
 * Final Project
 * The implementation of the Task class
 *
 */

#include "task.h"
#include <iostream>
using std::cout;

Task::Task()
{
	partsCost = 0;
	laborCost = 0;
	next = NULL;
}

Task::Task( const string &s, float parts, float labor )
{
	name = s;
	partsCost = parts;
	laborCost = labor;
	next = NULL;
}

void Task::printTask()
{
	cout << "        " << name << "\n";
	cout << "        Parts Cost: $" << partsCost << "\n";
	cout << "        Labor Cost: $" << laborCost << "\n";
}

float Task::getParts()
{
	return partsCost;
}

float Task::getLabor()
{
	return laborCost;
}
