//**********************************************************************
//Author: Chloe Byrd, Jay Goodroe, Caleb Ellis, and Tori Dean
//Name: Binary Heap Test Driver
//Purpose: Tests the BinaryHeap by reading graph data from a file,
//        inserting adjacent vertices into the heap, and removing them 
//        in priority order.
//Incoming: File input (ScooterWeights.txt)
//Outgoing: Shows output revealing inserted values and removal order
//Return: int (Exit for the program status)
//**********************************************************************
#include <iostream>
#include <fstream>
#include "BinaryHeap.h"

using namespace std;

const string FILE_NAME = "ScooterWeights.txt";

//**********************************************************************
//Name: Main (Binary Heap Test Driver)
//Purpose: Tests the BinaryHeap by reading graph data from a file,
//        inserting adjacent vertices into the heap, and removing them 
//        in priority order.
//Incoming: File input (ScooterWeights.txt)
//Outgoing: Shows output revealing inserted values and removal order
//Return: int (Exit for the program status)
//**********************************************************************
int main() {
    ifstream graphData;
    int numVertices = 0;
    int thisVertice = 0;
    int adjacentVertice = 0;
    char marker;
    char throwAway;

//**********************************************************************
//OPENFILE
//**********************************************************************
    graphData.open(FILE_NAME);
    if (!graphData.is_open()) {
        cout << FILE_NAME << ": Error opening file." << endl;
        return 1;
    }

//**********************************************************************
//SkipHeaderLines
//**********************************************************************
    for (int i = 0; i < 6; i++) {
        graphData.get(throwAway);
        while (throwAway != '\n') {
            graphData.get(throwAway);
        }
    }
    
//**********************************************************************
// ReadVertexCount
//**********************************************************************
    graphData >> numVertices;

    cout << "WELCOME TO THE BINARY MIN HEAP TEST!" << endl;


//**********************************************************************
// InitializeHeap
//**********************************************************************
    BinaryHeap heap;
    heap.MaxHeap();

//**********************************************************************
// InsertValuesIntoHeap
//**********************************************************************
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

//**********************************************************************
//RemoveValuesFromHeap
//**********************************************************************
    int removedValue = heap.remove();
    while (removedValue != -1) {
        cout << removedValue << " ";
        removedValue = heap.remove();
    }

    cout << endl;

//**********************************************************************
// Close File
//**********************************************************************
    graphData.close();
    return 0;
}
*/
