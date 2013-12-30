/* Edward Schembor
 * Final Project
 * The .h file for the Task_List class
 *
 */

#include <string>
using std::string;

#define TASKS 5

class Task_List
{
public:
	Task_List();

	void setPartsCost( int task, float price );
	float getPartsCost( int task );

	void setLaborCost( int task, float price );
	float getLaborCost( int task );

	string getName( int task );

	void printList();

private:
	float laborCosts[TASKS];
	float partCosts[TASKS];
	static const string names[];
};
