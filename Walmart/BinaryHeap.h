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

    void ResizeArray();
    void PercolateUp(int nodeIndex);
    void PercolateDown(int nodeIndex);
    int insert(int e);
    bool isFull();

public:
    void MaxHeap();
    virtual ~BinaryHeap();
};


#endif
