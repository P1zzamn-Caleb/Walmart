#include "BinaryHeap.h"
#include <iostream>
using namespace std;

//********************************************************************************
// Author: Jay Goodroe
// Name: ResizeArray
// Purpose: Doubles heap array capacity when full.
// Incoming: none
// Outgoing: heapArray replaced with larger array, allocationSize updated
// Return: void
//********************************************************************************
void BinaryHeap::ResizeArray() {
    int newAllocationSize = allocationSize * 2;
    HeapNode* newArray = new HeapNode[newAllocationSize];

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
// Name: ~BinaryHeap (Destructor)
// Purpose: Frees dynamically allocated heap memory
// Incoming: none
// Outgoing: heapArray memory released
// Return: none
//********************************************************************************
BinaryHeap::~BinaryHeap() {
    delete[] heapArray;
}

//********************************************************************************
// Author: Jay Goodroe
// Name: BinaryHeap Constructor
// Purpose: Initializes heap with default capacity and zero size
// Incoming: none
// Outgoing: heapArray allocated, heapSize and allocationSize initialized
// Return: none
//********************************************************************************
BinaryHeap::BinaryHeap() {
    allocationSize = 10;
    heapArray = new HeapNode[allocationSize];
    heapSize = 0;
}

//********************************************************************************
// Author: Jay Goodroe
// Name: isFull
// Purpose: Checks whether the heap array has reached capacity.
// Incoming: none
// Outgoing: none
// Return: bool - true if full, false otherwise
//********************************************************************************
bool BinaryHeap::isFull() {
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
bool BinaryHeap::isEmpty() {
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
void BinaryHeap::insert(int vertex, int distance) {
    if (isFull()) 
        ResizeArray(); 

    heapArray[heapSize] = {vertex, distance };
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
HeapNode BinaryHeap::remove() {
    if (heapSize == 0) {
        // cout << "Heap is empty." << endl;
        return HeapNode{ -1, -1 };
    }

    HeapNode minNode = heapArray[0];

    heapArray[0] = heapArray[heapSize - 1];
    heapSize--;

    if (heapSize > 0) {
        PercolateDown(0);
    }

    return minNode;
}


//********************************************************************************
// Author: Jay Goodroe
// Name: PercolateUp
// Purpose: Restores min-heap property after insertion
// Incoming: index of inserted node
// Outgoing: heap reordered if needed
// Return: void
// // Reference: This function was from the zybook.
//********************************************************************************
void BinaryHeap::PercolateUp(int index) {
    while (index > 0) {
        // Compute the parent node's index
        int parent = (index - 1) / 2;

        // Check for a violation of the max-heap property
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
void BinaryHeap::PercolateDown(int index) {
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