#ifndef _BINARY_HEAP_H
#define _BINARY_HEAP_H

struct HeapNode {
    int vertex;
    int distance;
};

class BinaryHeap {
private:
    HeapNode* heapArray;
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
    void insert(int vertex, int distance);
    HeapNode remove();
};

#endif



