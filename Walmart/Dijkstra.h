//********************************************************************************
// Author: Jay Goodroe & Caleb Ellis
// Name: Dijkstra Shortest Path Algorithm
// Purpose: Computes the shortest path from a starting vertex to all other
//          vertices in a weighted directed graph using a binary min-heap
//          (priority queue). Then reconstructs and prints the shortest path
//          from start to end.
// Incoming: 
//      LL* graph          - adjacency list representation of graph
//      int numVertices    - number of vertices in graph
//      int start          - starting vertex
//      int end            - destination vertex
// Outgoing:
//      Prints shortest distance and path to console
// Return:
//      void
//********************************************************************************

#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

#include "BinaryHeap.h"
#include "LL.h"
#include <iostream>
#include <climits>

using namespace std;

void dijkstra(LL* graph, int numVertices, int start, int end) {

    int* dist = new int[numVertices];
    int* prev = new int[numVertices];
    bool* visited = new bool[numVertices];

    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = false;
    }

    dist[start] = 0;

    BinaryHeap pq;

    pq.insert(start, 0);

    while (!pq.isEmpty()) {

        HeapNode node = pq.remove();

        if (node.vertex == -1)
            break;

        int u = node.vertex;

        if (!visited[u]) {
            visited[u] = true;

            Node* temp = graph[u].head;

            while (temp != nullptr) {
                int v = temp->connection;
                int weight = temp->weight;

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.insert(v, dist[v]);
                }

                temp = temp->next;
            }
        }
    }

    if (dist[end] == INT_MAX) {
        cout << "No path found." << endl;
        delete[] dist;
        delete[] prev;
        delete[] visited;
        return;
    }

    cout << endl << "======================================" << endl;
    cout << "        SHORTEST PATH RESULT" << endl;
    cout << "======================================" << endl << endl;

    cout << "Shortest Distance: " << dist[end] << endl << endl;

    int path[100];
    int count = 0;

    for (int v = end; v != -1; v = prev[v]) {
        path[count++] = v;
    }

    cout << "Path: " << endl;

    for (int i = count - 1; i >= 0; i--) {
        cout << "Step " << (count - i) << ": " << path[i];

        if (i != 0)
            cout << " -> " << path[i - 1];

        cout << endl;
    }

    cout << endl << "======================================" << endl ;

    delete[] dist;
    delete[] prev;
    delete[] visited;
}

#endif