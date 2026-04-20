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

template <class T> class Node;
template <class T> class LL;
template <class T> class BinaryHeap;


//*************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
//Name: Node
//Purpose: This represents a single edge in the adjacency list, storing the connected
//			vertex, edge weight, and pointer to the next node.
//Incoming: int w (weight), int c (connected vertex), Node* node (next pointer)
//Outgoing: Initializes a Node object
//Return: none
//**************************************************************************************
template <class T>
class Node
{
public:
	Node<T>* next;
	int weight;
	T connection;

	Node<T>(int w, T c, Node<T>* node) : weight(w), connection(c), next(node) {};
	friend class LL<T>;
	friend class BinaryHeap<T>;
};

//*************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
//Name: LL (Linked List)
//Purpose: This represents a linked list used in the adjacency list to store all
//			edges connected to a single vertex.
//Incoming: none
//Outgoing: Initializes an empty linked list
//Return: none
//**************************************************************************************
template <class T>
class LL
{
public:
	Node<T>* head;

	LL<T>() : head(nullptr) {};

//*************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
//Name: Insert
//Purpose: Inserts a new node at the beginning of the linked list
//Incoming: int e (edge weight), int c (connected vertex)
//Outgoing: Updates the linked list structure
//Return: none
//**************************************************************************************
	void Insert(int e, T c);

//*************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
//Name: Print
//Purpose: Traverses and displays all nodes in the linked lsit
//Incoming: None
//Outgoing: Shows output of connections and weights
//Return: none
//**************************************************************************************
	void Print()const;
};

//********************************************************************************
// Author: Caleb Ellis (Editted by Chloe)
// Name: Insert
// Purpose: Inserts weights in order in LL
// Incoming: int e, T c
// Outgoing: updated LL
// Return: none
//********************************************************************************
template <class T>
void LL<T>::Insert(int e, T c) {
	head = new Node<T>(e, c, head);

}


//********************************************************************************
// Author: Caleb Ellis (Editted by Chloe)
// Name: Print
// Purpose: Traverses and displays all nodes in the linked list 
// Incoming: none
// Outgoing: Shows output of connections and weights
// Return: none
//********************************************************************************
template <class T>
void LL<T>::Print()const
{
	Node<T>* temp = head;

	while (temp != nullptr)
	{
		cout << temp->connection << " " << temp->weight << " ";
		temp = temp->next;
	}
}


#endif
