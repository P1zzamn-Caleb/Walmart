#include "Queue.h"
#include <iostream>
using namespace std;

bool Queue::EnQ(int e) {
	bool success = false;
	if (!IsFull()) {
		data[back % MAX] = e;
		back++;
		// data[back++ % MAX] = e;
		success = true;
	}
	return success;
}

bool Queue::DeQ(int& e) {
	bool success = false;
	if (!IsEmpty()) {
		e = data[front % MAX];
		front++;
		// e = data[front++ % MAX];
		success = true;
	}
	return success;
}

Queue::Queue() :front(0), back(0) {}

bool Queue::IsEmpty()const {
	return front == back;
}

bool Queue::IsFull()const {
	return back - front == MAX;
}

bool Queue::EnQ(int e) {
	bool success = false;
	if (!IsFull()) {
		data[back % MAX] = e;
		back++;
		// data[back++ % MAX] = e;
		success = true;
	}
	return success;
}

bool Queue::DeQ(int& e) {
	bool success = false;
	if (!IsEmpty()) {
		e = data[front % MAX];
		front++;
		// e = data[front++ % MAX];
		success = true;
	}
	return success;