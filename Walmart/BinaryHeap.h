#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H

#include <iostream>
#include "LL.h"
using namespace std;

struct HeapNode {
    int vertex;
    int distance;
};

class BinaryHeap {
private:
    //int* heapArray; >>
    HeapNode* heapArray;
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
    bool isEmpty();
    int insert(int v, int w);
    HeapNode remove();
};

#endif

