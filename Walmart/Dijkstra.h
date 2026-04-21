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
#include <limits>

using namespace std;

//********************************************************************************
// Author: Jay Goodroe, Caleb Ellis, Tori Dean (edited)
// Name: dijkstra
//Purpose: Computes the shortest path from the starting vertex to a destination
//        vertex using Dijkstra's Algorithm
//Incoming: LL* graph (adjacency list)
//          int numVertices (number of vertices)
//          int start (starting vertex_
//          int end (destination vertex)
//Outgoing: Shows the output of the shortest distance and path
//Return: None
//********************************************************************************
template <class T>
void dijkstra(LL<T>* graph, int numVertices, int start, int end, const string names[]) {

    T* dist = new T[numVertices];
    int* prev = new int[numVertices];
    bool* visited = new bool[numVertices];

    for (int i = 0; i < numVertices; i++) {
        dist[i] = std::numeric_limits<T>::max();
        prev[i] = -1;
        visited[i] = false;
    }

    dist[start] = 0;

    BinaryHeap<T> pq;

    pq.insert(start, 0);

    while (!pq.isEmpty()) {

        HeapNode<T> node = pq.remove();

        if (node.vertex == -1)
            break;

        int u = node.vertex;

        if (!visited[u]) {
            visited[u] = true;

            Node<T>* temp = graph[u].getHead();

            while (temp != nullptr) {
                int v = temp->connection;
                T weight = temp->weight;

                if (dist[u] != std::numeric_limits<T>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.insert(v, dist[v]);
                }

                temp = temp->next;
            }
        }
    }

//********************************************************************************
//Name: CheckPath
//Purpose: Determines if a valid path exists to destination
//********************************************************************************
    if (dist[end] == std::numeric_limits<T>::max()) {
        cout << "No path found." << endl;
        delete[] dist;
        delete[] prev;
        delete[] visited;
        return;
    }

//********************************************************************************
//Name: DisplayResults
//Purpose: Outputs shortest distance and path
//********************************************************************************
    cout << endl << "======================================" << endl;
    cout << "        SHORTEST PATH RESULT" << endl;
    cout << "======================================" << endl << endl;

    cout << "Shortest Distance: " << dist[end] << endl << endl;

    int path[100];
    int count = 0;

//********************************************************************************
//Name: BuildPath
//Purpose: Reconstructs path from destination to start
//********************************************************************************
    for (int v = end; v != -1; v = prev[v]) {
        path[count++] = v;
    }

    cout << "Path: " << endl;

    for (int i = count - 1; i >= 0; i--) {
        cout << "Step " << (count - i) << ": " << names[path[i]] << " (" << path[i] << ")";

        if (i != 0)
            cout << " -> " << names[path[i - 1]] << " (" << path[i - 1] << ")";

        cout << endl;
    }

    cout << endl << "======================================" << endl ;

//********************************************************************************
//Name: Cleanup
//Purpose: Frees dynamically allocated memory
//********************************************************************************
    delete[] dist;
    delete[] prev;
    delete[] visited;
}

#endif
