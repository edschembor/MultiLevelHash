/* Edward Schembor
 * Final Project
 * Main File
 *
 */

#include "table.h"
#include "random_op.h"
#include <iostream>
using std::cin;

#define SEED 1

main()
{

	Table<int> table;

	unsigned int seed;
	int i;
	int j;
	int key;
	char operation;
	int *data;
	int range;
	int operations;
	int *checkInsert;
	int *dataCheck;

	seed = SEED;
	data = NULL;
	key = 0;
	operation = 'A';
	range = 0;
	operations = 0;
	checkInsert = NULL;
	dataCheck = NULL;

	cout << "Enter a random number range: \n";
	cin >> range;
	cout << "Enter the number of operations to be performed:\n";
	cin >> operations;

	Random_operation RandOp(SEED, range);

	for( i = 0; i <= operations; i++)
	{
		RandOp.Randomize_next_op();
		operation = RandOp.Get_op();
		key = RandOp.Get_key();

		if(operation == 'G')
		{
			table.MLH_get( key );
		}
		else if( operation == 'D')
		{
			dataCheck = table.MLH_delete( key );
			if( dataCheck != NULL )
			{
				delete dataCheck;
			}
		}
		else if( operation == 'I')
		{
			data = new(int);
			*data = i;
			checkInsert = table.MLH_insert( key, data );
			if( checkInsert == NULL )
			{
				delete data;
			}
		}

		if( (i%100 == 0) && (range <=100) )
		{
			cout << "\n --------------- \n"; 
			table.MLH_print(1);
			cout << "Steps taken so far: " << table.getSteps() << "\n";
		}

	}

	cout << "\nFINAL STEPS TAKEN: " << table.getSteps() << "\n";

}
