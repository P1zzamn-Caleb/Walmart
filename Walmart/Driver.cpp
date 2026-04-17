#include <iostream>
#include <fstream>
#include "LL.h"

using namespace std;
const string FILE_NAME = "ScooterWeights.txt";
//*************************************************************************************
//Author: Jay Goodroe
//Name: Main (Driver - Walmart Weighted Graph Navigation System)
//Purpose: Entry point of program. Loads graph from file, builds
//			adjacency list, displays graph structure, and allows
//			user to input start/end nodes for shortest path navigation.
//Incoming: File input (ScooterWeights.txt), user input (start/end aisles)
//Outgoing: Displays graph structure and navigation results
//Return: 	int (program exit result)
//*************************************************************************************

int main() {
	
	ifstream graphData;
	
	int numVertices = 0, 
	thisVertice = -1, 
	connectionWeight = -1, 
	connectionVertice = 0,
	startVertice = 0, 
	endVertice = 0;

//**************************************************************************************
//Name: OpenFile
//Purpose: Opens input file containing graph data
//Incoming: FILE_NAME constant
//Outgoing: File stream opened or error message
//Return: none
//**************************************************************************************
	graphData.open(FILE_NAME);
	if (!graphData.is_open())
	{
		cout << ": Error opening file -> " << FILE_NAME << endl;
		cout << "Program Ending......." << endl;
		return 1;
	}

//**************************************************************************************
//Name: DisplayWelcome
//Purpose: Shows program introduction message to user
//Incoming: none
//Outgoing: Console output
//Return: none
//**************************************************************************************
	cout << "*******************************************************" << endl;
	cout << " 			WALMART WEIGHTED GRAPH NAVIGATION           " << endl;
	cout << "*******************************************************" << endl;

	cout << "Loading store layout...." << endl;

//**************************************************************************************
//Name: ReadVertexCount
//Purpose: Reads number of vertices from input file
//Incoming: file stream
//Outgoing: numVertices updated
//Return: none
//**************************************************************************************
	graphData >> numVertices;
	cout << "Total aisles (vertices): " << numVertices << endl;
	cout << Building graph connections..." << endl << endl;

//**************************************************************************************
//Name: InitializeGraph
//Purpose: Creates array of linked lists for adjacency representation 
//Incoming: numVertices
//Outgoing: dynamic LL array created
//Return: none
//**************************************************************************************
	LL* vertices = new LL[numVertices];

//**************************************************************************************
//Name: BuildAdjacencyList
//Purpose: Reads file and forms adjacency list graph
//Incoming: file stream data
//Outgoing: populated linked list graph structure
//Return: none
//**************************************************************************************
	for (int i = 0; i < numVertices; i++)
	{
		graphData >> thisVertex;
		cout << "Processing Aisle " << thisVertex << endl;
		
		while (true)
		{
			graphData >> connectionVertex;
			
			if (connectionVertex == -1) {
				cout << " End of connections for Aisle " << thisVertex << endl;
				break;
			}
			graphData >> connectionWeight;
			vertices[thisVertex].Insert(connectionWeight, connectionVertex);

			cout << " Connected to Aisle " << connectionVertex << " | Weight: " << connectionWeight << endl;
		}
		cout << endl;
	}
	graphData.close();	

//**************************************************************************************
//Name: PrintGraph
//Purpose: Displays final adjacency list representation of graph
//Incoming: LL array
//Outgoing: printed graph structure
//Return: none
//**************************************************************************************
	cout << "*******************************************************" << endl;
	cout << " 			FINAL WAREHOUSE MAP (ADJACENCY LIST)        " << endl;
	cout << "*******************************************************" << endl;

	for (int j = 0; j < numVertices; j++)
	{
		cout << "Aisle " << j << " -> ";
		vertices[j].Print();
		cout << endl;
	}

//**************************************************************************************
//Name: UserNavigationMenu
//Purpose: Allows user to input start and end aisles for navigation
//Incoming: user input (start, end, choice)
//Outgoing: Display navigation process (placeholder for shortest path)
//Return: none
//**************************************************************************************
	int start, end;
	char choice;

	cout << endl << "********************************************************" << endl;
	cout << " 							NAVIGATION MENU						"  << endl;
	cout << endl << "********************************************************" << endl;

	cout << "Available aisles: 0 to " << numVertices - 1 << endl;

	do {
		cout << endl << "Enter starting aisle: ";
		cin >> start;

		cout << "Enter destination aisle: ";
		cin >> end;

		cout << endl << "Calculating shortest path from " << start << " to " << end << "..." << endl;
		cout << "RESULT: Shortest path computing (integration pending)." << endl;

		cout << endl << "Would you like to try another route? (y/n): ";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');

//**************************************************************************************
//Name: Cleanup
//Purpose: Frees dynamically allocated memory
//Incoming: vertices array
//Outgoing: memory deallocated
//Return: none
//**************************************************************************************
delete[] vertices;

cout << endl << "Program terminated successfully." << endl;
	
return 0;
}


