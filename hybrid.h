/* Edward Schembor
 * Final Project
 * The .h file for the Hybrid class
 *
 */

#include "car.h"

class Hybrid : public Car
{
public:
	Hybrid( int, int, float, const string &, int, float, const string &, float, float, float);
	
	void setMotorPower( float );
	float getMotorPower();

	void setUsage( float );
	float getUsage();

	void setBatteryCapacity( float );
	float getBatteryCapacity();

	virtual void print();

private:
	float motorPower;
	float usage;
	float batteryCapacity;
};
