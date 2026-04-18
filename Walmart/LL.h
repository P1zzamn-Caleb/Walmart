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
public:
	Node* next;
	int weight;
	int connection;

	Node(int w, int c, Node* node) : weight(w), connection(c), next(node) {};
	friend class LL;
	friend class BinaryHeap;
};

class LL
{
public:
	Node* head;

	LL() : head(nullptr) {};

	void Insert(int e, int c);
	void Print()const;
};



#endif
