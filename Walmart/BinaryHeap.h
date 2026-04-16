#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H

#include <iostream>
using namespace std;

class BinaryHeap {
private:
    int* heapArray;
    int allocationSize;
    int heapSize;

    void ResizeArray();
    void PercolateUp(int nodeIndex);
    void PercolateDown(int nodeIndex);

public:
    void MaxHeap();
    virtual ~BinaryHeap();
};


#endif
