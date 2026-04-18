#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H

#include <iostream>
#include "LL.h"
using namespace std;

class BinaryHeap {
private:
    int* heapArray;
    int* connectionArr;
    int allocationSize;
    int heapSize;
    int back;

public:
    void MinHeap();
    ~BinaryHeap();

    void PercolateUp(int nodeIndex);
    void PercolateDown(int nodeIndex);
    void ResizeArray();

    bool isFull();
    int insert(int e, int c);
    int remove(int& minVertice);
};

#endif

