#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H

#include <iostream>
using namespace std;

class BinaryHeap {
private:
    int* heapArray;
    int allocationSize;
    int heapSize;
    int back;

public:
    void MaxHeap();
    ~BinaryHeap();

    void PercolateUp(int nodeIndex);
    void PercolateDown(int nodeIndex);
    void ResizeArray();

    bool isFull();
    int insert(int e);
    int remove();
};

#endif

