//*************************************************************************************
// Authors: Caleb Ellis, Tori Dean, Chloe Byrd, Jay Goodroe
// Start Date: 16. April 2026
// Name: CS 355 Walmart Graph assignement
// Description: This file contains the LL that will implement chain linking into a
//				hashing table.
//*************************************************************************************
#ifndef _LL_H
#define _LL_H
#include <iostream>
using namespace std;

//*************************************************************************************
//Name: Node
//Purpose: This represents a single edge in the adjacency list, storing the connected
//			vertex, edge weight, and pointer to the next node.
//Incoming: int w (weight), int c (connected vertex), Node* node (next pointer)
//Outgoing: Initializes a Node object
//Return: none
//**************************************************************************************
class Node
{
public:
	Node* next;
	int weight;
	int connection;

	Node(int w, int c, Node* node) : weight(w), connection(c), next(node) {};
	friend class LL;
	friend class BinaryHeap;
};

//*************************************************************************************
//Name: LL (Linked List)
//Purpose: This represents a linked list used in the adjacency list to store all
//			edges connected to a single vertex.
//Incoming: none
//Outgoing: Initializes an empty linked list
//Return: none
//**************************************************************************************
class LL
{
public:
	Node* head;

	LL() : head(nullptr) {};

//*************************************************************************************
//Name: Insert
//Purpose: Inserts a new node at the beginning of the linked list
//Incoming: int e (edge weight), int c (connected vertex)
//Outgoing: Updates the linked list structure
//Return: none
//**************************************************************************************
	void Insert(int e, int c);

//*************************************************************************************
//Name: Print
//Purpose: Traverses and displays all nodes in the linked lsit
//Incoming: None
//Outgoing: Shows output of connections and weights
//Return: none
//**************************************************************************************
	void Print()const;
};

#endif
