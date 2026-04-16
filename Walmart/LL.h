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

class Node
{
	Node* next;
	int weight;
public:
	Node(int w, Node* node) : weight(w), next(node) {};
	friend class LL;
};

class LL
{
	Node* head;
public:
	LL() : head(nullptr) {};

	bool Search(int e)const;
	void InsertAtFront(int e);
	bool Remove(int e);
	void Print()const;
};

//********************************************************************************
// Author: Caleb Ellis (Reviewed and Editted by Chloe Byrd)
// Name: Remove
// Purpose: Removes e
// Incoming: int e
// Outgoing: updated LL, true or false based on if it is successful or unsuccessful
// Return: true or false based on if it is successful or unsuccessful
//********************************************************************************
bool LL::Remove(int e)
{
	bool removed = false;
	if (head == nullptr)
	{
	}
	else if (head->weight == e)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
		removed = true;
	}
	else
	{
		Node* curr = head;
		Node* prev = head;
		while (curr->next != nullptr && curr->weight != e)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr->weight == e)
		{
			prev->next = curr->next;
			delete curr;
			curr = nullptr;
			removed = true;
		}
	}
	return removed;
}
//********************************************************************************
// Author: Caleb Ellis
// Name: Search
// Purpose: Searches for e
// Incoming: weight e
// Outgoing: true or false based on if it is found
// Return: true or false based on if it is found
//********************************************************************************
bool LL::Search(int e)const
{
	bool found = false;
	if (head != nullptr)
	{
		Node* curr = head;
		while (curr->weight != e && curr->next != nullptr)
		{
			curr = curr->next;
		}
		if (curr->weight == e)
			found = true;
	}
	return found;
}

//********************************************************************************
// Author: Caleb Ellis
// Name: InsertAtFront
// Purpose: Inserts at the front of the LL
// Incoming: int e
// Outgoing: updated LL
// Return: none
//********************************************************************************
void LL::InsertAtFront(int e)
{
	head = new Node(e, head);
}

//********************************************************************************
// Author: Caleb Ellis
// Purpose: Prints LL
// Incoming: none
// Outgoing: none
// Return: none
//********************************************************************************
void LL::Print()const
{
	Node* temp = head;

	while (temp != nullptr)
	{
		cout << temp->weight << " ";
		temp = temp->next;
	}
}

#endif