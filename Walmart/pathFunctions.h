#ifndef _PATHFUNCTIONS_H
#define _PATHFUNCTIONS_H

#include "LL.h"
#include "BinaryHeap.h"

void shortestPath(LL* vertices, int numVertices, int startVertex, int endVertex);
void printPath(int startVertex, int endVertex, int* previous);
#endif
