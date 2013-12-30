/* Edward Schembor
 * Final Project
 * Main File for Part 2
 *
 */

#define COLORS 5
#define GASNUMBER 3
#define VEHICLES 4

#include "table.h"
#include "hybrid.h"
#include "motorcycle.h"
#include "bus.h"
#include "task_list.h"

#include <iostream>
using std::cout; //Do I need this?
using std::cin;

/*Method Declarations*/
void printMainMenu();
void taskListChange();
void addVehicle();
void printColors();
void printGas();
void addTasks( Vehicle *vehicle );
void selectVehicle();

Table< Vehicle > table;
Task_List task_list;
int id; //Keeps track of the current id
float totalSales; //Keeps track of the total sales of the maintenance center
Vehicle *selected; //A pointer to a vehicle selected by the user

const string colors[COLORS] = {"Red", "Blue", "White", "Black", "Green"};
const string gas[GASNUMBER] = {"Regular", "Premium", "Diesel"};

main()
{
	int input;
	bool cont;

	input = 0;
	cont = true;
	selected = NULL;
	id = 1;
	totalSales = 0;
	
	while( cont == true )
	{
		printMainMenu();
		cin >> input;

		cout << "\n";

		switch( input )
		{
			case 1:
				/*Adds a vehicle to the list*/
				addVehicle();
				id++;
				break;
			case 2:
				selectVehicle();
				break;
			case 3:
				/*Prints out the ids of the cars in line*/
				if( table.getKeyCount() == 0 )
					cout << "Sorry, there are no vehicles in the shop\n";
				else
					table.MLH_print(0);
				break;
			case 4:
				/*Allows the user to change a task's price*/
				taskListChange();
				break;
			case 5:
				/*Prints the List of Tasks*/
				task_list.printList();
				break;
			case 6:
				/*Prints the total sales*/
				cout << "\nTotal Sales: $" << totalSales << "\n";
				break;
			case 7:
				/*Stops the program and deconstructs*/
				cont = false;
				break;
			default:
				cout << "Error --- Improper Input";
				break;
		}

	}

}

void printMainMenu()
{
//Prints out the main menu options

	cout << "\n---------------\n";
	cout << "Please Select an Option\n";
	cout << "1) Add a Vehicle\n";
	cout << "2) Select a Vehcile\n";
	cout << "3) View the Current Line\n";
	cout << "4) Change a Task's Price\n";
	cout << "5) Print the Task List\n";
	cout << "6) View the Total Sales\n";
	cout << "7) Exit\n";
}

void taskListChange()
{
//Allows the user to change the price of a certain task in the task_list

	int taskNumber;
	int costType;
	float change;

	taskNumber = 0;
	costType = 0;
	change = 0;

	cout << "\n---------------\n";
	cout << "Which task would you like to change the price of?\n";
	task_list.printList();
	cin >> taskNumber;

	if( (taskNumber > TASKS) || (taskNumber <= 0) )
		cout << "Error --- Invalid Input\n";
	else
	{

		cout << "Which cost do you want to change?\n";
		cout << "1) The Labor Cost\n";
		cout << "2) The Parts Cost\n";
		cin >> costType;
		
		if( (costType > 2) || (costType <= 0) )
			cout << "Error --- Invalid Input\n";
		else
		{
			cout << "What would you like the new cost to be?\n";
			cin >> change;
		}

		if( change <= 0 )
			cout << "Error --- Invalid Input\n";
		else
		{
			if( costType == 1 )
				task_list.setLaborCost( taskNumber - 1 , change );
			else if( costType == 2 )
				task_list.setPartsCost( taskNumber - 1, change );

			cout << "\n The price has been changed!\n";
		}

	}

}

void addVehicle()
{
//Allows the user to create and add a vehicle. Asks for parameters based 
//on which type of vehicle is being created

	Vehicle *temp;
	int vehicleType;
	int year;
	float mileage;
	int color;
	int engineSize;
	float pollutionLevel;
	int gasType;
	float motorPower;
	float usage;
	float batteryCapacity;
	float front;
	float back;
	int cap;

	temp = NULL;
	vehicleType = 0;
	year = 0;
	mileage = 0;
	color = 0;
	engineSize = 0;
	pollutionLevel = 0;
	gasType = 0;
	motorPower = 0;
	usage = 0;
	batteryCapacity = 0;
	front = 0;
	back = 0;
	cap = 0;

	cout << "Which type of vehicle would you like to add?\n";
	cout << "1) Car\n";
	cout << "2) Hybrid\n";
	cout << "3) Motorcycle\n";
	cout << "4) Bus\n";

	cin >> vehicleType;

	if( ( vehicleType > VEHICLES ) || (vehicleType <= 0 ) )
		cout << "Error --- Improper Input\n";
	else
	{
		cout << "What is the vehicle's model year?\n";
		cin >> year;
		cout << "What is the vehicle's current mileage?\n";
		cin >> mileage;
		cout << "What is the vehicle's color?\n";
		printColors();
		cin >> color;
		if( (color > COLORS) || (color <= 0) )
		{
			cout << "Invalid color --- Color set to red\n";
			color = 1;
		}
	}

	switch( vehicleType )
	{
		case 1:
			cout << "What is your car's engine size?\n";
			cin >> engineSize;
			cout << "What is your car's pollution level?\n";
			cin >> pollutionLevel;
			cout << "What is your car's gas type?\n";
			printGas();
			cin >> gasType;
			if( (gasType > GASNUMBER) || (gasType <= 0) )
			{
				cout << "Invalid Gas Type --- Gas set to Regular\n";
				gasType = 1;
			}
			temp = new Car( id, year, mileage, colors[color-1], engineSize, pollutionLevel, gas[gasType - 1] );
			break;
		case 2:
			cout << "What is your hybrid's engine size?\n";
			cin >> engineSize;
			cout << "What is your hybrid's pollution level?\n";
			cin >> pollutionLevel;
			cout << "What is your hybrid's gas type?\n";
			printGas();
			cin >> gasType;
			if( (gasType > GASNUMBER) || (gasType <= 0) )
			{
				cout << "Invalid Gas Type --- Gas set to Regular\n";
				gasType = 0;
			}
			cout << "What is your hybrid's motor power?\n";
			cin >> motorPower;
			cout << "What is your hybrid's current usage?\n";
			cin >> usage;
			cout << "What is your hybrid's battery capacity?\n";
			cin >> batteryCapacity;
			temp = new Hybrid( id, year, mileage, colors[color - 1], engineSize, pollutionLevel, gas[gasType - 1], motorPower, usage, batteryCapacity );
			break;
		case 3:
			cout << "What is your motorcycle's engine size?\n";
			cin >> engineSize;
			cout << "What is the size of your front wheel?\n";
			cin >> front;
			cout << "What is the size of your back wheel?\n";
			cin >> back;
			temp = new Motorcycle( id, year, mileage, colors[color - 1], engineSize, front, back );
			break;
		case 4:
			cout << "What is your bus' capacity?\n";
			cin >> cap;
			temp = new Bus( id, year, mileage, colors[color - 1], cap );
			break;
		default:
			break;
	}

	if( (vehicleType < VEHICLES ) && (vehicleType > 0) )
	{
		addTasks( temp );
		table.MLH_insert( id, temp );
		cout << "\n VEHICLE ADDED! \n";
	}

}

void printColors()
{
//Prints out the possible colors

	int i;

	for( i = 0; i < COLORS; i++)
		cout << i+1 << ") " << colors[i] << "\n";
}

void printGas()
{
//Prints out the possible gas types

	int i;

	for( i = 0; i < GASNUMBER; i++)
		cout << i+1 << ") " << gas[i] << "\n";

}

void addTasks( Vehicle *vehicle )
{
//Allows the user to create a new Task instance which is then added to 
//a specific vehicle in the data structure

	int input;
	bool cont;
	Task *pointer;

	input = 0;
	cont = true;
	pointer = NULL;

	while( cont == true )
	{
		cout << "\nWhat tasks would you like added to the vehicle?\n";
		task_list.printList();
		cout << TASKS + 1 << ") None - Exit this menu\n";
		cin >> input;
		if( (input > TASKS) || (input <= 0) )
			cont = false;
		else
		{
			pointer = new Task( task_list.getName(input-1), task_list.getPartsCost(input-1), task_list.getLaborCost(input-1) );

			vehicle->addTask( pointer );
			cout << "Task Added!\n";
		}

	}
}

void selectVehicle()
{
//Allows the user to select a vehicle from the data structure and then 
//selection an operation to perform on the vehicle

	int input;
	int input2;
	bool cont;

	input = 0;
	cont = true;

	if( table.getKeyCount() == 0 )
	{
		cout << "Sorry, there are no vehicles in the shop\n";
		cont = false;
	}else{

		cout << "Please select a vehicle by typing in its id:\n";
		table.MLH_print(0);
		cin >> input;
	
		selected = table.MLH_get( input );
		if( selected == NULL )
			cout << "Error - No vehicle with that id exists\n";
		else
		{
			selected->print();
		}
	}

	while( cont == true )
	{
		cout << "What would you like to do with this vehicle?\n";
		cout << "1) Add a task\n";
		cout << "2) Checkout the vehicle\n";
		cout << "3) Print the vehicle's attributes\n";
		cout << "4) Exit\n";
	
		cin >> input2;

		switch( input2 )
		{
			case 1:
				addTasks(selected);
				break;
			case 2:
				totalSales += selected->checkout();
				selected = table.MLH_delete( input );
				delete selected;
				cont = false;
				break;
			case 3:
				selected->print();
				break;
			case 4:
				cont = false;
				break;
			default:
				cout << "Invalid Input\n";
				break;
		}
	}

}
