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
//Purpose: This represents a binary min-heap used as a priority queue to store
//         vertices and their associated distance values for shortest path calculation.
//Incoming: None
//Outgoing: Provides a priority queue structure for shortest path processing
//Return: None
//********************************************************************************************

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

    bool isFull();
    bool isEmpty();
    void insert(int vertex, T distance);
    HeapNode<T> remove();
};

//********************************************************************************
// Author: Jay Goodroe
// Name: PercolateUp
// Purpose: Restores min-heap property after insertion
// Incoming: index of inserted node
// Outgoing: heap reordered if needed
// Return: void
// // Reference: This function was from the zybook.
//********************************************************************************
template <class T>
void BinaryHeap<T>::PercolateUp(int index) {
    while (index > 0) {
        // Compute the parent node's index
        int parent = (index - 1) / 2;

        // Check for a violation of the min-heap property
        if (heapArray[index].distance >= heapArray[parent].distance) {
            // No violation, so percolate up is done.
            break;
        }
        else {
            // Swap heapArray[nodeIndex] and heapArray[parentIndex]
            swap(heapArray[index], heapArray[parent]);
            // Continue the loop from the parent node
            index = parent;
        }
    }
}

//********************************************************************************
// Author: Jay Goodroe
// Name: PercolateDown
// Purpose: Restores min-heap property after removal of root node
// Incoming: index of root node
// Outgoing: heap reordered if needed
// Return: void
// Reference: This function was from the zybook.
//********************************************************************************
template <class T>
void BinaryHeap<T>::PercolateDown(int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heapSize && heapArray[left].distance < heapArray[smallest].distance)
            smallest = left;

        if (right < heapSize && heapArray[right].distance < heapArray[smallest].distance)
            smallest = right;

        if (smallest == index) break;

        swap(heapArray[index], heapArray[smallest]);
        index = smallest;
    }
}

//********************************************************************************
// Author: Jay Goodroe
// Name: ResizeArray
// Purpose: Doubles heap array capacity when full.
// Incoming: none
// Outgoing: heapArray replaced with larger array, allocationSize updated
// Return: void
//********************************************************************************
template <class T>
void BinaryHeap<T>::ResizeArray() {
    int newAllocationSize = allocationSize * 2;
    HeapNode<T>* newArray = new HeapNode<T>[newAllocationSize];

    // Copy from existing array to new array
    for (int i = 0; i < heapSize; i++) {
        newArray[i] = heapArray[i];
    }

    // Delete old array and set pointer to new
    delete[] heapArray;
    heapArray = newArray;
    allocationSize = newAllocationSize;
}

//********************************************************************************
// Author: Jay Goodroe
// Name: BinaryHeap Constructor
// Purpose: Initializes heap with default capacity and zero size
// Incoming: none
// Outgoing: heapArray allocated, heapSize and allocationSize initialized
// Return: none
//********************************************************************************
template <class T>
BinaryHeap<T>::BinaryHeap() {
    allocationSize = 10;
    heapArray = new HeapNode<T>[allocationSize];
    heapSize = 0;
}

//********************************************************************************
// Author: Jay Goodroe
// Name: ~BinaryHeap (Destructor)
// Purpose: Frees dynamically allocated heap memory
// Incoming: none
// Outgoing: heapArray memory released
// Return: none
//********************************************************************************
template <class T>
BinaryHeap<T>::~BinaryHeap() {
    delete[] heapArray;
}

//********************************************************************************
// Author: Jay Goodroe
// Name: isFull
// Purpose: Checks whether the heap array has reached capacity.
// Incoming: none
// Outgoing: none
// Return: bool - true if full, false otherwise
//********************************************************************************
template <class T>
bool BinaryHeap<T>::isFull() {
    return heapSize == allocationSize;
}

//********************************************************************************
// Author: Jay Goodroe
// Name: isEmpty
// Purpose: Checks whether the heap array is empty.
// Incoming: none
// Outgoing: none
// Return: bool - true if empty, false otherwise
//********************************************************************************
template <class T>
bool BinaryHeap<T>::isEmpty() {
    return heapSize == 0;
}


//********************************************************************************
// Author: Jay Goodroe
// Name: insert
// Purpose: Inserts a (vertex, distance) pair into min-heap and restores heap order
// Incoming: vertex ID and distance value
// Outgoing: heap array updated
// Return: void
//********************************************************************************
template <class T>
void BinaryHeap<T>::insert(int vertex, T distance) {
    if (isFull())
        ResizeArray();

    heapArray[heapSize] = { vertex, distance };
    PercolateUp(heapSize);
    heapSize++;
}

//********************************************************************************
// Author: Jay Goodroe
// Name: remove
// Purpose: Removes and returns node with smallest distance from heap root
// Incoming: none
// Outgoing: heap reordered after removal
// Return: HeapNode containing vertex and distance
//********************************************************************************
template <class T>
HeapNode<T> BinaryHeap<T>::remove() {
    if (heapSize == 0) {
        // cout << "Heap is empty." << endl;
        return HeapNode<T>{ -1, T() };
    }

    HeapNode<T> minNode = heapArray[0];

    heapArray[0] = heapArray[heapSize - 1];
    heapSize--;

    if (heapSize > 0) {
        PercolateDown(0);
    }

    return minNode;
}

#endif
