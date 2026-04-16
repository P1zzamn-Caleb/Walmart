#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
//#include <queue>
//#include <fstream>
#include <limits>

using namespace std;

struct Edge {
    int adjVertex; //where we are going
    int weight; // how far it is
    Edge* next;

    Edge(int a, int w) : adjVertex(a), weight(w), next(nullptr) {}

};

class Graph {             //Keeping our class broad

private:
    int V;
    Edge** adjList;     //Where the graph is actually stored Inner v = all edges from that node Outer V = All Nodes


public:
    // Constructor
    Graph(int vertices) : V(vertices) {};
    // Destructor
    ~Graph();
    void addEdge(int vertex, int adjVertex, int weight);

    // Dijkstra-style shortest path
    void findShortestPath(int start);

    // BFS (unweighted comparison)
    //void bfs(int start);

    // Print final path
    //void printPath(int goal);

    // Optional debugging
    void printGraph();
};

#endif
