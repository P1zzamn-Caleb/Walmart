#include "BinaryHeap.h"
#include <iostream>
using namespace std;

//********************************************************************************
// Author: Jay Goodroe
// Name: PercolateUp
// Purpose: Moves a newly inserted element upward in the heap until
//          the min-heap property is restored.
// Incoming: int nodeIndex - the index of the node to move upward
// Outgoing: heapArray may be rearranged
// Return: void
// // Reference: This function was from the zybook.
//********************************************************************************
void BinaryHeap:: PercolateUp(int nodeIndex) {
    while (nodeIndex > 0) {
        // Compute the parent node's index
        int parentIndex = (nodeIndex - 1) / 2;

        // Check for a violation of the max-heap property
        if (heapArray[nodeIndex] >= heapArray[parentIndex]) {
            // No violation, so percolate up is done.
            return;
        }
        else {
            // Swap heapArray[nodeIndex] and heapArray[parentIndex]
            int temp = heapArray[nodeIndex];
            heapArray[nodeIndex] = heapArray[parentIndex];
            heapArray[parentIndex] = temp;

            // Continue the loop from the parent node
            nodeIndex = parentIndex;
        }
    }
}

//********************************************************************************
// Author: Jay Goodroe
// Name: PercolateDown
// Purpose: Moves the root element downward in the heap until the
//          min-heap property is restored after a removal.
// Incoming: int nodeIndex - the index of the node to move downward
// Outgoing: heapArray may be rearranged
// Return: void
// Reference: This function was from the zybook.
//********************************************************************************
void BinaryHeap::PercolateDown(int nodeIndex) {
    int childIndex = 2 * nodeIndex + 1;
    int value = heapArray[nodeIndex];

    while (childIndex < heapSize) {
        // Find the max among the node and all the node's children
        int maxValue = value;
        int maxIndex = -1;
        int i = 0;
        while (i < 2 && i + childIndex < heapSize) {
            if (heapArray[i + childIndex] < maxValue) {
                maxValue = heapArray[i + childIndex];
                maxIndex = i + childIndex;
            }
            i++;
        }

        // Check for a violation of the max-heap property
        if (maxValue == value) {
            return;
        }
        else {
            // Swap heapArray[nodeIndex] and heapArray[maxIndex]
            int temp = heapArray[nodeIndex];
            heapArray[nodeIndex] = heapArray[maxIndex];
            heapArray[maxIndex] = temp;

            // Continue loop from the max index node
            nodeIndex = maxIndex;
            childIndex = 2 * nodeIndex + 1;
        }
    }
}

//********************************************************************************
// Author: Jay Goodroe
// Name: ResizeArray
// Purpose: Doubles the size of the heap array when it becomes full.
// Incoming: none
// Outgoing: heapArray is resized and allocationSize is updated
// Return: void
// // Reference: This function was from the zybook.
//********************************************************************************
void BinaryHeap::ResizeArray() {
    int newAllocationSize = allocationSize * 2;
    int* newArray = new int[newAllocationSize];
    if (newArray) {
        // Copy from existing array to new array
        for (int i = 0; i < heapSize; i++) {
            newArray[i] = heapArray[i];
        }

        // Delete old array and set pointer to new
        delete[] heapArray;
        heapArray = newArray;

        // Update allocation size
        allocationSize = newAllocationSize;
    }
}

//********************************************************************************
// Author: Jay Goodroe
// Name: ~BinaryHeap
// Purpose: Destructor that releases the dynamically allocated heap array.
// Incoming: none
// Outgoing: memory used by heapArray is freed
// Return: none
// Reference: This function was from my notes in the dynamic array class.
//********************************************************************************
BinaryHeap::~BinaryHeap() {
    delete[] heapArray;
}

//********************************************************************************
// Author: Jay Goodroe
// Name: MaxHeap
// Purpose: Initializes the binary heap with a starting array size
//          and sets counters to zero.
// Incoming: none
// Outgoing: allocationSize, heapArray, back, and heapSize are initialized
// Return: void
//********************************************************************************
void BinaryHeap::MaxHeap() {
    allocationSize = 1;
    heapArray = new int[allocationSize];
    back = 0;
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
// Name: insert
// Purpose: Inserts a new value into the min-heap and restores heap order.
// Incoming: int e - the value to insert
// Outgoing: heapArray, heapSize, and back may be updated
// Return: int - the current heap size after insertion
//********************************************************************************
int BinaryHeap::insert(int e) {
    if (isFull()) {
        ResizeArray();
    }

    heapArray[heapSize] = e;   
    PercolateUp(heapSize);    
    heapSize++;
    back = heapSize;

    return heapSize;         
}

//********************************************************************************
// Author: Jay Goodroe
// Name: remove
// Purpose: Removes and returns the minimum value from the root of the heap.
// Incoming: none
// Outgoing: heapArray, heapSize, and back may be updated
// Return: int - the minimum value removed, or -1 if the heap is empty
//********************************************************************************
int BinaryHeap::remove() {
    if (heapSize == 0) {
        cout << "Heap is empty." << endl;
        return -1;
    }

    int minValue = heapArray[0];

    heapArray[0] = heapArray[heapSize - 1];
    heapSize--;
    back = heapSize;

    if (heapSize > 0) {
        PercolateDown(0);
    }

    return minValue;
}