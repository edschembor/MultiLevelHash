/* Edward Schembor
 * Final Project
 * The .h file for the Car class
 *
 */

#include "vehicle.h"

class Car : public Vehicle
{
public:
	Car( int, int, float, const string &, int, float, const string &);

	void setEngineSize( int );
	int getEngineSize();

	void setPollutionLevel( float );
	float getPollutionLevel();

	string getGasType();

	virtual void print();

private:
	int engineSize;
	float pollutionLevel;
	string gasType;
};
