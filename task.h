/* Edward Schembor
 * Final Project
 * The .h file for the Task class
 *
 */

#include <string>
using std::string;

class Task
{
public:
	Task();
	Task( const string &, float, float );
	void printTask();
	float getParts();
	float getLabor();
	Task *next;

private:
	string name;
	float partsCost;
	float laborCost;
};
