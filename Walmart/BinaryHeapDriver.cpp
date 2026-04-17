/*
#include <iostream>
#include <fstream>
#include "BinaryHeap.h"

using namespace std;

const string FILE_NAME = "ScooterWeights.txt";

int old_main() {
    ifstream graphData;
    int numVertices = 0;
    int thisVertice = 0;
    int adjacentVertice = 0;
    char marker;
    char throwAway;

    graphData.open(FILE_NAME);
    if (!graphData.is_open()) {
        cout << FILE_NAME << ": Error opening file." << endl;
        return 1;
    }

    for (int i = 0; i < 6; i++) {
        graphData.get(throwAway);
        while (throwAway != '\n') {
            graphData.get(throwAway);
        }
    }

    graphData >> numVertices;

    cout << "WELCOME TO THE BINARY MIN HEAP TEST!" << endl;

    BinaryHeap heap;
    heap.MaxHeap();

    for (int i = 0; i < numVertices; i++) {
        graphData >> thisVertice;

        graphData >> ws;
        marker = graphData.peek();

        while (marker != '-') {
            graphData >> adjacentVertice;
            cout << "Inserting: " << adjacentVertice << endl;
            heap.insert(adjacentVertice);

            graphData >> ws;
            marker = graphData.peek();
        }

        graphData >> marker;
    }

    cout << endl;
    cout << "Removing values from min heap in priority order:" << endl;

    int removedValue = heap.remove();
    while (removedValue != -1) {
        cout << removedValue << " ";
        removedValue = heap.remove();
    }

    cout << endl;

    graphData.close();
    return 0;
}
*/