#include "pathFunctions.h"

//********************************************************************************
// Author: Tori Dean
// Name: shortestPath
// Purpose: Finds the shortest path from a starting vertex to all other vertices
//			using Dijkstra's algorithm with a binary min-heap priority queue. It
//			also reconstructs the path to the end/target vertex using printPath().
// Incoming: LL* vertices - adjacency list representation of the graph
//			 int numVertices - total number of vertices in the graph
//			 int startVertex - starting point for the search
//			 int endVertex - destination vertex to reconstruct path for
// Outgoing: dist[] - shortest known distance from startVertex to each vertex
//			 visited[] - array that tracks processed vertices
//			 prev[] - stores predecessor info for path reconstruction
//			 Heap is used to efficiently select next closest vertex
// Return: void
// Source: adapted from Dijkstra's in Zybook
//********************************************************************************
void shortestPath(LL* vertices, int numVertices, int startVertex, int endVertex, const string realWorldV[])
{
	const int INFINITE = 999999;

	int* dist = new int[numVertices];
	bool* visited = new bool[numVertices];
	int* prev = new int[numVertices];

	BinaryHeap heap;
	heap.MinHeap();
	// initializes all vertices to unvisited & the distances to infinite
	for (int i = 0; i < numVertices; i++)
	{
		dist[i] = INFINITE;
		visited[i] = false;
		prev[i] = -1;
	}

	// changes the starting vertex's distance to 0 and puts it in the heap
	dist[startVertex] = 0;
	heap.insert(startVertex, 0);

	// main Dijkstra loop using priority queue (binary heap)
	while (!heap.isEmpty()) {
		// looks for the closest unprocessed node
		HeapNode minNode = heap.remove();
		int currentVertex = minNode.vertex;
		///int currentDist = minNode.distance; // new

		// checks if the vertex was already been visited, skips if true
		if (!visited[currentVertex]) {
			visited[currentVertex] = true;
			if (currentVertex == endVertex)
				break;
			// looks at the adjacent vertices
			Node* temp = vertices[currentVertex].getHead();

			while (temp != nullptr) {
				int adjV = temp->getConnection();
				int weight = temp->getWeight();

				//updates the distance if a shorter path is found

				/*cout << "Trying: " << currentVertex << " -> " << adjV
					<< " newDist = " << dist[currentVertex] + weight << endl; */
				if (!visited[adjV] && dist[currentVertex] + weight < dist[adjV])
				{
					dist[adjV] = dist[currentVertex] + weight;
					prev[adjV] = currentVertex;
					heap.insert(adjV, dist[adjV]);
				}
				temp = temp->getNext(); // move to next neighbor
			}
		}
	}
	// prints final shortest path result
	cout << "Shortest distance: " << dist[endVertex] << endl;
	printPath(startVertex, endVertex, prev, realWorldV);

	delete[] dist;
	delete[] visited;
	delete[] prev;
}

//********************************************************************************
// Author: Tori Dean
// Name: printPath
// Purpose: Reconstructs and prints the shortest path from startVertex to endVertex
//			using the array from shortestPath().
// Incoming: int start - starting vertex
//			 int end - destination vertex
//			 int* prev - array storing the predecessor of each vertex
// Outgoing: Prints the path to the console in reverse (end -> start)
// Return: void
// Source: adapted from Dijkstra's and Getting the Shortest Path in Zybook
//********************************************************************************
void printPath(int start, int end, int* prev, const string realWorldV[]) {
	if (prev[end] == -1 && start != end) {
		cout << "No path exists." << endl;
		return;
	}
	int current = end;

	cout << "Path: ";
	while (current != -1) {
		cout << realWorldV[current];
		if (current == start)
			break;

		cout << " <- ";
		current = prev[current];
	}
	cout << endl;
}