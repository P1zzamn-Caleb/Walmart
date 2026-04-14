#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

class Queue {
	int data[MAX];
	int front;
	int back;
public:
	Queue();
	bool IsEmpty()const;
	bool IsFull()const;
	bool EnQ(int e);
	bool DeQ(int& e);
	void Print()const;
};

#endif
