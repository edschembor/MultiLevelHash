/* Edward Schembor
 * Final Project
 * The .h file for the Bus class
 *
 */

#include "vehicle.h"

class Bus : public Vehicle
{
public:
	Bus( int, int, float, const string &, int );

	void setCapacity( int );
	int getCapacity();

	virtual void print();

private:
	int capacity;
};
