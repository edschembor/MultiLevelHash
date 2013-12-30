/* Edward Schembor
 * Final Project
 * Node .h File
 *
 * This is the code for the node class used in the multi-level hash table.
 * It allows for the deletion, addition, getting, and printing of key/data combinations
 */

#define MAX 5

#include "ML_hash.h"
#include<iostream>
#include<stddef.h>
using std::cout;

// Forward declaration of the Table class
template< typename NODETYPE > class Table;

template< typename NODETYPE >
class Node
{
friend class Table< NODETYPE >;

public:
	Node(); //Constructor
	void insert( int key, NODETYPE *data );
	NODETYPE * deleteFromNode( int key );
	NODETYPE * get( int key );
	int compress(); //Helper function
	void node_print();
	
private:
	int keys[MAX]; //List of key elements in each node
	NODETYPE *data[MAX]; //List of pointers to the data
	Node< NODETYPE > *pointers[MAX]; //List of pointers to other nodes
	int keysBelow;
};

//Constructor
template< typename NODETYPE >
Node< NODETYPE >::Node()
{
//Sets everything to NULL to avoid pointer issues later

	int i;
	for( i = 0; i < MAX; i++ )
	{
		keys[i] = 0;
		data[i] = NULL;
		pointers[i] = NULL;
	}
	
	keysBelow = 0;
}

template< typename NODETYPE >
void Node< NODETYPE >::insert( int key, NODETYPE *data )
{
//Inserts a key into the first empty slot in a node

	int i;

	for( i = 0; i < MAX; i++ )
	{
		if( keys[i] == 0 )
		{
			keys[i] = key;
			this->data[i] = data;
			break;
		}
	}
}

template< typename NODETYPE >
NODETYPE * Node< NODETYPE >::deleteFromNode( int key )
{
//Deletes a given key from a node and returns the key's data pointer

	int i;
	NODETYPE *pointer;

	i = 0;

	for( i = 0; i < MAX; i++ )
	{
		if( keys[i] == key )
		{
			keys[i] = 0;
			pointer = data[i];
			return pointer;
		}
	}

	return NULL;
}

template< typename NODETYPE >
NODETYPE * Node< NODETYPE>::get( int key )
{
//Searches a node for a specified key

	int i;
	NODETYPE *pointer;

	i = 0;
	
	for( i = 0; i < MAX; i++ )
	{
		if( keys[i] == key )
		{
			pointer = data[i];
			return pointer;
		}
	}
	return NULL;
}

template< typename NODETYPE >
int Node< NODETYPE >::compress()
{
//Moves the member from the lower nodes to their parent node

	int i;
	int j;
	int count; //Keeps track of which spots in the node have been filled
	int deletedLeaves;
	Node< NODETYPE > *nodePointer;

	deletedLeaves = 0;
	count = 0;

	for( i = 0; i < MAX; i++ )
	{
		if( pointers[i] != NULL )
		{
			deletedLeaves++;
			for( j = 0; j < MAX; j++ )
			{
				if( pointers[i]->keys[j] != 0 )
				{
					keys[count] = pointers[i]->keys[j];
					data[count] = pointers[i]->data[j];	
					pointers[i]->data[j] = NULL;
					count++; 
				}
			}
			nodePointer = pointers[i];
			pointers[i] = NULL;
			delete nodePointer;
		}
	}

	return deletedLeaves;
}

template< typename NODETYPE >
void Node< NODETYPE >::node_print()
{
//Uses recusrion to print out all the keys containted below a certain node
	int i;
	int j;
	int count;

	count = 0;

	for( i = 0; i < MAX; i++ )
	{
		if( pointers[i] != NULL )
		{
			count++;
			pointers[i]->node_print();
		}
	}

	if( count == 0 )
	{
		for( j = 0; j < MAX; j++ )
		{
			if( keys[j] != 0 )
			{
				cout << keys[j] << " ";
				cout << *data[j] << "\n";
			}
		}
	}
}
