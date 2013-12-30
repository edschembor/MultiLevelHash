/* Edward Schembor
 * Final Project
 * The Table class .h file
 *
 */

#define DEEPEST 9

#include "node.h"
#include "ML_hash.h"
#include <iostream>
using std::cout;
using std::ostream;

template< typename NODETYPE >
ostream& operator << (ostream &o, const Table< NODETYPE > &t);

template< typename NODETYPE >
class Table
{
friend ostream& operator << <>(ostream &o, const Table< NODETYPE> &t);

public:
	Table(); //Constructor
	~Table(); //Destructor
	NODETYPE * MLH_insert( int key, NODETYPE *data );
	NODETYPE * MLH_delete( int key );
	NODETYPE * MLH_get( int key );
	void MLH_expand( Node< NODETYPE > *pointer, int level, int key );
	void MLH_print(int k);
	void MLH_set_print_option();
	int getSteps();
	void deconstructHelper( Node< NODETYPE > *pointer );
	int getKeyCount();

private:
	//Utility funciton to create a new ndoe
	Node< NODETYPE > *getNewNode();

	Node< NODETYPE > first;
	int deepestLevel;
	int nodeCount;
	bool printAll;
	int countPerLevel[DEEPEST];
	int steps;
};

//Constructor
template< typename NODETYPE >
Table< NODETYPE >::Table()
{
//Sets all variables to 0 and printAll to true

	int i;

	for( i = 0; i < DEEPEST; i++)
		countPerLevel[i] = 0;

	countPerLevel[0] = 1;
	deepestLevel = 0;
	nodeCount = 0;
	printAll = true;
	steps = 0;
}

//Deconstructor
template< typename NODETYPE >
Table< NODETYPE >::~Table()
{
	Node< NODETYPE > *nodePointer;

	nodePointer = &first;

	deconstructHelper( nodePointer );

}


template< typename NODETYPE >
NODETYPE * Table< NODETYPE >::MLH_insert( int key, NODETYPE *data )
{
//Inserts a key/data combination into the key's respective node, which is
//found using a hash funciton. If a node is full, its contents are placed
//into expanded child nodes based on a new hash

	bool added; //Become true once the key has been added to the list
	Node< NODETYPE > *nodePointer;
	static Node< NODETYPE > *tempPointers[DEEPEST]; //Used to keep track of the nodePointers path when traversing back up the list to increment keysBelow
	int currentHash;
	int currentLevel;

	added = false;
	nodePointer = &first;
	currentHash = 0;
	currentLevel = 0;

//First checks if the key is already in the list
	if( MLH_get( key ) != NULL )
		return NULL;

//Moves down the list using ML_hash until it arrives at an open node
	while( added == false )
	{
		if( nodePointer->keysBelow >= MAX )
		{
			currentHash = ML_hash( currentLevel + 1, key );
			if( nodePointer->pointers[currentHash - 1] == NULL )
			{
				MLH_expand( nodePointer, currentLevel + 1, key );
				countPerLevel[currentLevel + 1]++;
			}
			tempPointers[currentLevel] = nodePointer;
			nodePointer = nodePointer->pointers[currentHash - 1];
			currentLevel++;
			steps++;
		}else{
			nodePointer->insert( key, data );
			nodePointer->keysBelow++;
			added = true;
			steps++;		
		}
	}

//Changes deepestLevel if inserting caused expansion to a deeper level
	if( currentLevel > deepestLevel)
		deepestLevel = currentLevel;

//Moves back up the array, increasing itemsBelow in each node
	while( currentLevel > 0)
	{
		nodePointer = tempPointers[currentLevel - 1];
		nodePointer->keysBelow++;
		currentLevel--;
		steps++;
	}

	return data;
	
}

template< typename NODETYPE >
NODETYPE * Table< NODETYPE >::MLH_delete( int key )
{
//Deletes a given key from the table and compresses nodes if they have 5 
//or less keys below them

	Node< NODETYPE > *nodePointer;
	Node< NODETYPE > *tempPointers[deepestLevel + 1];
	NODETYPE *foundData;
	bool deleted;
	int currentHash;
	int currentLevel;
	int leavesDeleted;

	nodePointer = &first;
	deleted = false;
	currentHash = 0;
	currentLevel = 0;

//Moves down to where the key should be and deletes it if it exists
	while( deleted == false )
	{
		if( nodePointer->keysBelow > MAX )
		{
			currentHash = ML_hash( currentLevel + 1, key );
			tempPointers[currentLevel] = nodePointer;
			if( nodePointer->pointers[currentHash - 1] == NULL)
				return NULL;
			else
				nodePointer = nodePointer->pointers[currentHash - 1];
			currentLevel++;
			steps++;
		}else{
			tempPointers[currentLevel] = nodePointer;
			foundData = nodePointer->deleteFromNode( key );
			deleted = true;
			steps++;
		}
	}

//Moves back up, decreasing itemsBelow, and collapsing it <=5 elements
	while( (currentLevel >= 0) && (foundData != NULL) )
	{
		nodePointer = tempPointers[currentLevel];
		steps++;
		nodePointer->keysBelow--;
		if( nodePointer->keysBelow <= MAX )
			{
				leavesDeleted = nodePointer->compress();
				countPerLevel[currentLevel]--;
				nodeCount -= leavesDeleted;
				steps++;
				if( countPerLevel[currentLevel] == 0 )
					deepestLevel = currentLevel;
			}
		currentLevel--;
	}

	return foundData;
}

template< typename NODETYPE >
NODETYPE * Table< NODETYPE >::MLH_get( int key )
{
//Returns pointer to the key's data if in the table and NULL if not
	Node< NODETYPE > *nodePointer;
	int currentLevel;
	int currentHash;

	nodePointer = &first;
	currentLevel = 1;
	currentHash = ML_hash( currentLevel, key );

//Do while????
	while( nodePointer->pointers[currentHash - 1] != NULL)
	{
		nodePointer = nodePointer->pointers[currentHash - 1];
		currentLevel++;
		if( currentLevel < DEEPEST )
			currentHash = ML_hash( currentLevel, key );
		else
			break;
		steps++;
	}

	return nodePointer->get( key );
}

template< typename NODETYPE >
void Table< NODETYPE >::MLH_expand( Node< NODETYPE > *pointer, int level, int key )
{
//Creates the necessary child nodes and inserts them with the keys from 
//their parent node

	int currentHash;
	int i;

//For each key in the node being expanded, a new node is created for it
//if necessary and adds the key to its respective node
	for( i = 0; i < MAX; i++ )
	{
		if( pointer->keys[i] != 0)
		{
			currentHash = ML_hash( level, pointer->keys[i]) - 1;
			if( pointer->pointers[currentHash] == NULL)
			{
				pointer->pointers[currentHash] = getNewNode();
				nodeCount++;
			}
			pointer->pointers[currentHash]->insert( pointer->keys[i], pointer->data[i] );
			pointer->pointers[currentHash]->keysBelow++;
			pointer->keys[i] = 0;
			pointer->data[i] = NULL;
		}
		steps++;
	}

//If the key needs a new node, create it and add the key to it
	currentHash = ML_hash( level, key ) - 1;
	if( pointer->pointers[currentHash] == NULL)
	{
		pointer->pointers[currentHash] = getNewNode();
		nodeCount++;
		steps++;
	}
	
}

template< typename NODETYPE >
void Table< NODETYPE >::MLH_print(int k)
{
//Prints out the leadfcount, deepestLevel, and number of keys in the 
//structure if printAll is true

	int i;
	Node< NODETYPE > *nodePointer;

	nodePointer = &first;

	if( k == 1 )
	{
		cout << "\nNumber of Hash Nodes: " << nodeCount + 1;
		cout << "\nDeepest level: " << deepestLevel;
		cout << "\nNumber of items: " << nodePointer->keysBelow << "\n";
	}

	if( printAll == true )
		nodePointer->node_print();
	
}

template< typename NODETYPE > class Table;
template< typename NODETYPE >
ostream& operator << (ostream &out, const Table< NODETYPE > &t)
{
//The overloading of the << operator so it prints the table contents

	t.MLH_print();
}

template< typename NODETYPE >
Node< NODETYPE > *Table< NODETYPE >::getNewNode()
{
// Returns a newly created node

	return new Node< NODETYPE >();
}

template< typename NODETYPE >
void Table< NODETYPE >::MLH_set_print_option()
{
//Changes the printAll option

	if( printAll == true)
		printAll = false;
	else
		printAll = true;
}

template< typename NODETYPE >
int Table< NODETYPE >::getSteps()
{
	return steps;
}

template< typename NODETYPE >
void Table< NODETYPE >::deconstructHelper( Node< NODETYPE > *p)
{
	int i;
	int j;
	Node< NODETYPE > *pointer;
	NODETYPE *data;

	for( i = 0; i < MAX; i++ )
	{
		if( p->pointers[i] != NULL )
		{
			deconstructHelper( p->pointers[i] );
			pointer = p->pointers[i];
			p->pointers[i] = NULL;
			for( j = 0; j < MAX; j++ )
			{
				if( pointer->data[j] != NULL )
				{
					data = MLH_delete( pointer->keys[j] );
					delete data;
				}
			}  
			delete pointer;
		}
	}

}

template< typename NODETYPE >
int Table< NODETYPE >::getKeyCount()
{
	Node< NODETYPE > *pointer;
	pointer = &first;
	return pointer->keysBelow;
}
