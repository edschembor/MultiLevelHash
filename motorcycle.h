/* Edward Schembor
 * Final Project
 * The .h file for the Motorcycle class
 *
 */

#include "vehicle.h"

class Motorcycle : public Vehicle
{
public:
	Motorcycle(int, int, float, const string &, int, float, float );

	void setEngineSize( int );
	int getEngineSize();

	void setFrontWheel( float );
	float getFrontWheel();

	void setBackWheel( float );
	float getBackWheel();

	virtual void print();

private:
	int engineSize;
	float frontWheelSize;
	float backWheelSize;
};
