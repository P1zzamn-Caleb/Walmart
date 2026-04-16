#include "BinaryHeap.h"
#include <iostream>
using namespace std;


void BinaryHeap:: PercolateUp(int nodeIndex) {
    while (nodeIndex > 0) {
        // Compute the parent node's index
        int parentIndex = (nodeIndex - 1) / 2;

        // Check for a violation of the max-heap property
        if (heapArray[nodeIndex] <= heapArray[parentIndex]) {
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



void BinaryHeap::PercolateDown(int nodeIndex) {
    int childIndex = 2 * nodeIndex + 1;
    int value = heapArray[nodeIndex];

    while (childIndex < heapSize) {
        // Find the max among the node and all the node's children
        int maxValue = value;
        int maxIndex = -1;
        int i = 0;
        while (i < 2 && i + childIndex < heapSize) {
            if (heapArray[i + childIndex] > maxValue) {
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

void BinaryHeap::ResizeArray() {
    int newAllocationSize = allocationSize * 2;
    int* newArray = new int[newAllocationSize];
    if (newArray) {
        // Copy from existing array to new array
        for (int i = 0; i < allocationSize; i++) {
            newArray[i] = heapArray[i];
        }

        // Delete old array and set pointer to new
        delete[] heapArray;
        heapArray = newArray;

        // Update allocation size
        allocationSize = newAllocationSize;
    }
}

BinaryHeap::~BinaryHeap() {
    delete[] heapArray;
}

void BinaryHeap::MaxHeap() {
    allocationSize = 1;
    heapArray = new int[allocationSize];
    heapSize = 0;
}