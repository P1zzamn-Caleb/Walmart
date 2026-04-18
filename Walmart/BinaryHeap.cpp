#include "BinaryHeap.h"
#include <iostream>
using namespace std;

//********************************************************************************
// Author: Jay Goodroe (edited by Tori Dean)
// Name: PercolateUp
// Purpose: Moves a newly inserted element upward in the heap until
//          the min-heap property is restored (its distance value is >= its parent).
// Incoming: int nodeIndex - the index of the node to move upward
// Outgoing: heapArray may be rearranged
// Return: void
// // Reference: This function was from the zybook. Updated for HeapNode
//********************************************************************************
void BinaryHeap:: PercolateUp(int nodeIndex) {
    while (nodeIndex > 0) {
        // Compute the parent node's index
        int parentIndex = (nodeIndex - 1) / 2;

        // Check for a violation of the max-heap property
        if (heapArray[nodeIndex].distance >= heapArray[parentIndex].distance) {
            // No violation, so percolate up is done.
            return;
        }
        else {
            // Swap heapArray[nodeIndex] and heapArray[parentIndex]
            HeapNode temp = heapArray[nodeIndex];
            heapArray[nodeIndex] = heapArray[parentIndex];
            heapArray[parentIndex] = temp;

            // Continue the loop from the parent node
            nodeIndex = parentIndex;
        }
    }
}

//********************************************************************************
// Author: Jay Goodroe (edited by Tori Dean)
// Name: PercolateDown
// Purpose: Moves the root element downward in the heap until the
//          min-heap property is restored after a removal of root element.
// Incoming: int nodeIndex - the index of the node to move downward
// Outgoing: heapArray may be rearranged to maintain min-heap structure.
// Return: void
// Reference: This function was from the zybook.Updated for HeapNode
//********************************************************************************
void BinaryHeap::PercolateDown(int nodeIndex) {
    int childIndex = 2 * nodeIndex + 1;
    int value = heapArray[nodeIndex].distance;

    while (childIndex < heapSize) {
        // Find the max among the node and all the node's children
        int maxValue = value;
        int maxIndex = -1;
        int i = 0;
        while (i < 2 && i + childIndex < heapSize) {
            if (heapArray[i + childIndex].distance < maxValue) {
                maxValue = heapArray[i + childIndex].distance;
                maxIndex = i + childIndex;
            }
            i++;
        }

        // Check for a violation of the min-heap property
        if (maxValue == value) {
            return;
        }
        else {
            // Swap heapArray[nodeIndex] and heapArray[maxIndex]
            HeapNode temp = heapArray[nodeIndex];
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
    HeapNode* newArray = new HeapNode[newAllocationSize];
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
// Name: MinHeap
// Purpose: Initializes the binary heap with a starting array size
//          and sets counters to zero.
// Incoming: none
// Outgoing: allocationSize, heapArray, back, and heapSize are initialized
// Return: void
//********************************************************************************
void BinaryHeap::MinHeap() {
    allocationSize = 1;
    heapArray = new HeapNode[allocationSize];
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
// Author: Tori Dean
// Name: isEmpty
// Purpose: Checks whether the heap array has nodes to process.
// Incoming: none
// Outgoing: none
// Return: bool - true if empty, false otherwise
//********************************************************************************
bool BinaryHeap::isEmpty() {
    return heapSize == 0;
}

//********************************************************************************
// Author: Jay Goodroe (Edited by Tori Dean)
// Name: insert
// Purpose: Inserts a new pair (vertex, distance) into the min-heap and restores
//          heap order.
// Incoming: int v - the vertex identifier
//           int w - distance value associated with the vertex
// Outgoing: heapArray, heapSize, and back may be updated
// Return: int - the current heap size after insertion
//********************************************************************************
int BinaryHeap::insert(int v, int d) {
    if (isFull()) {
        ResizeArray();
    }

    heapArray[heapSize].vertex = v;
    heapArray[heapSize].distance = d;
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
// Return: HeapNode (vertex & distance) of removed node. If heap is empty, returns
//         a node with vertex = -1;
//********************************************************************************
HeapNode BinaryHeap::remove() {
    if (heapSize == 0) {
        cout << "Heap is empty." << endl;
        HeapNode empty;
        empty.vertex = -1;
        empty.distance = -1;
        return empty;
    }

    HeapNode minNode = heapArray[0];

    heapArray[0] = heapArray[heapSize - 1];
    heapSize--;
    back = heapSize;

    if (heapSize > 0) {
        PercolateDown(0);
    }

    return minNode;
}