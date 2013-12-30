/* Edward Schembor
 * Final Project
 * The implementation of the Task_List class
 *
 */

#include <iostream>
#include "task_list.h"
using std::cout;

const string Task_List::names[TASKS] = { "General Check-up", "Brake Change", "Oil Change", "Tire Rotation", "Car Wash" };

Task_List::Task_List()
{
/*The constructor for the Task_List. Sets all prices to $50*/

	int i;
	for( i = 0; i < TASKS; i++)
	{
		partCosts[i] = 5;
		laborCosts[i] = 5;
	}
}

void Task_List::setPartsCost( int task, float price )
{
	partCosts[task] = price;
}

float Task_List::getPartsCost( int task )
{
	return partCosts[task];
}

void Task_List::setLaborCost( int task, float price )
{
	laborCosts[task] = price;
}

float Task_List::getLaborCost( int task )
{
	return laborCosts[task];
}

string Task_List::getName( int task )
{
	return names[task];
}

void Task_List::printList()
{
	int i;

	for( i = 0; i < TASKS; i++)
		cout << i+1 << ") " << names[i] << " --- Labor Cost: $" << laborCosts[i] << " --- Parts Cost: $" << partCosts[i] << "\n";
}
