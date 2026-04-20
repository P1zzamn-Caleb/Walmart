//**********************************************************************
//Author: Chloe Byrd, Jay Goodroe, Caleb Ellis, and Tori Dean
//Start Date: April 16, 2026
//Name: CS 355 Walmart Graph Assignment - Binary Heap
//Description: This file implements a templated Binary Heap used for  
//        priority queue operations in Dijkstra's algorithm. It stores
//        vertex distance pairs and maintains heap order based on minimum 
//        distance values.
//**********************************************************************

#ifndef _BINARY_HEAP_H
#define _BINARY_HEAP_H
#include <iostream>
using namespace std;

//********************************************************************************************
//Name: HeapNode
//Purpose: Stores a single element in the Binary Heap, containing a vertex and its associated
//        distance value for priority comparison
//Incoming: int vertex, int distance
//Outgoing: Stores heap node data
//Return: none
//********************************************************************************************
template <class T>
struct HeapNode {
    int vertex;
    T distance;
};

//********************************************************************************************
//Name: BinaryHeap
//Purpose: Frees dynamically allocated memory used by heap
//Incoming: None
//Outgoing: Deallocates heap memory
//Return: None
//********************************************************************************************

//***************************
//DESTRUCTOR
//***************************
template <class T>
class BinaryHeap {
private:
    HeapNode<T>* heapArray;
    int allocationSize;
    int heapSize;

    void PercolateUp(int nodeIndex);
    void PercolateDown(int nodeIndex);
    void ResizeArray();

public:
    BinaryHeap();
    ~BinaryHeap();

//********************************************************************************************
//Name: isFull
//Purpose: Checks if heap has reached maximum capacity
//Incoming: None
//Outgoing: Boolean result
//Return: None
//********************************************************************************************
    bool isFull();

//********************************************************************************************
//Name: isEmpty
//Purpose: Checks if heap contains no elements
//Incoming: None
//Outgoing: Boolean result
//Return: Bool
//********************************************************************************************
    bool isEmpty();

//********************************************************************************************
//Name: insert
//Purpose: Inserts a new vertex distance pair into the heap
//Incoming: int vertex, int distance
//Outgoing: Updated heap structure
//Return: None
//********************************************************************************************
    void insert(int vertex, int distance);

//********************************************************************************************
//Name: remove
//Purpose: Removes and returns the minimum distance node from the heap
//Incoming: None
//Outgoing: Updated heap structure
//Return: HeapNode (minimum element)
//********************************************************************************************
    HeapNode<T> remove();
};

#endif



