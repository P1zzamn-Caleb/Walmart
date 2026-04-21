//*************************************************************************************
// Authors: Caleb Ellis, Tori Dean, Chloe Byrd, Jay Goodroe
// Start Date: 16. April 2026
// Name: CS 355 Walmart Graph assignement
// Description: This file contains the LL that will be used in the adjacency list to store all
//			edges connected to a single vertex and their weights.
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
	T weight;
	int connection;

	Node<T>(T w, int c, Node<T>* node) : weight(w), connection(c), next(node) {};

	friend class LL<T>;
	friend class BinaryHeap<T>;
};

//*************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
//Name: LL (Linked List)
//Purpose: This represents a linked list used in the adjacency list to store all
//			edges connected to a single vertex.
//Incoming: none
//Outgoing: Provides a linked list representation of a vertex's adjacency list
//Return: none
//**************************************************************************************
template <class T>
class LL
{
	Node<T>* head;
public:
	LL<T>() : head(nullptr) {};
	~LL();

	Node<T>* getHead() const;
	void Insert(T e, int c);
	void Print()const;
};

//********************************************************************************
// Author: Tori Dean
// Name: ~LL
// Purpose: Frees memory for all dynamicaly allocated nodes in the linked list.
// Incoming: none
// Outgoing: none
// Return: none
//********************************************************************************

template <class T>
LL<T>::~LL() {
	Node<T>* current = head;
	while (current != nullptr) {
		Node<T>* toDelete = current;
		current = current->next;
		delete toDelete;
	}
	head = nullptr;
}

//********************************************************************************
// Author: Tori Dean
// Name: getHead
// Purpose: Returns a pointer to the head of the linked list
// Incoming: none
// Outgoing: none
// Return: Pointer to the first/head node in the list (Node<T>*)
//********************************************************************************
template <class T>
Node<T>* LL<T>::getHead() const {
	return head;
}

//********************************************************************************
// Author: Caleb Ellis (Editted by Chloe)
// Name: Insert
// Purpose: Inserts weights in order in LL
// Incoming: int e, T c
// Outgoing: updated LL
// Return: none
//********************************************************************************
template <class T>
void LL<T>::Insert(T e, int c) {
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
