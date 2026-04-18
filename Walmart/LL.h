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
#include "BinaryHeap.h"

class Node
{
	Node* next;
	int weight;
	int connection;
public:
	Node(int w, int c, Node* node) : weight(w), connection(c), next(node) {};
	friend class LL;
	friend class BinaryHeap;
};

class LL
{
	Node* head;
	int distance;
	int whoChangedMe;
public:
	LL() : head(nullptr), distance(0), whoChangedMe(0) {};

	void Insert(int e, int c);
	void Print()const;
	void insertWeights(BinaryHeap& heap, LL whoChangedObject);
	void adjustDistance(int d, int who);

	int getWhoChangedMe();
};



#endif
