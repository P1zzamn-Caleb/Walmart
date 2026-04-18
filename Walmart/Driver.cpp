#include <iostream>
#include <fstream>
#include "pathFunctions.h"

using namespace std;
const string FILE_NAME = "ScooterWeights.txt";

const string LOCATIONS[23] = {
	"Entrance",
	"Bread",
	"Produce",
	"Checkout",
	"Self-checkout",
	"Health",
	"Personal Care",
	"Frozen",
	"Women's Clothing",
	"Men's Clothing",
	"Party Supplies",
	"Kitchen",
	"Garden",
	"Deli",
	"Alcohol",
	"Shoes",
	"Kid's Clothing",
	"Arts & Crafts",
	"Home/Furniture",
	"Auto",
	"Dairy",
	"Toys",
	"Sports"
};
void LocationsMenu();
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
		thisVertex = -1,
		connectionWeight = -1,
		connectionVertex = 0,
		startVertex = 0,
		endVertex = 0;

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
	cout << "          WALMART WEIGHTED GRAPH NAVIGATION" << endl;
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
	cout << "Building graph connections..." << endl << endl;

//**************************************************************************************
//Name: InitializeGraph
//Purpose: Creates array of linked lists for adjacency representation 
//Incoming: numVertices
//Outgoing: dynamic LL array created
//Return: none
//**************************************************************************************
	LL* vertices = new LL[numVertices];


	               //// NOT SURE THIS IS NECESSARY ANYMORE
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
			connectionWeight -= 30;
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
	cout << "         FINAL WAREHOUSE MAP (ADJACENCY LIST)" << endl;
	cout << "*******************************************************" << endl;

	for (int j = 0; j < numVertices; j++)
	{
		cout << "Aisle " << j << " -> ";
		vertices[j].Print();
		cout << endl;
	}
	                   /// END OF NOT SURE THIS IS NECESSARY ANYMORE
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
	cout <<"                    NAVIGATION MENU"  << endl;
	cout << "********************************************************" << endl;

	LocationsMenu();

	do {
		cout << endl << "Enter starting aisle: ";
		cin >> start;

		cout << "Enter destination aisle: ";
		cin >> end;

		cout << endl << "Calculating shortest path from " << LOCATIONS[start] << " to " << LOCATIONS[end] << "..." << endl;
		cout << "RESULT: " << endl;
		shortestPath(vertices, numVertices, start, end, LOCATIONS);
		cout << endl;

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

//Author: Tori Dean
//Name: LocationsMenu
//Purpose: Provide the user with the names of aisles/sections and their vertices.
//		   They will reference it to pick their locations as integers.
//Incoming: none
//Outgoing: Displays a list of aisles/sections with their vertice reference.
//Return: 	none
void LocationsMenu()
{
	cout << endl << "****************************" << endl;
	cout << "Location Options:" << endl;
	for (int i = 0; i < 23; i++)
	{
		cout << "\"" << i << "\" - " << LOCATIONS[i] << endl;
	}
	/*cout << "\"0\" - Entrance" << endl;
	cout << "\"1\" - Bread" << endl;
	cout << "\"2\" - Produce" << endl;
	cout << "\"3\" - Checkout" << endl;
	cout << "\"4\" - Self-checkout" << endl;
	cout << "\"5\" - Health" << endl;
	cout << "\"6\" - Personal Care" << endl;
	cout << "\"7\" - Frozen" << endl;
	cout << "\"8\" - Women's Clothing" << endl;
	cout << "\"9\" - Men's Clothing" << endl;
	cout << "\"10\" - Party Supplies" << endl;
	cout << "\"11\" - Kitchen" << endl;
	cout << "\"12\" - Garden" << endl;
	cout << "\"13\" - Deli" << endl;
	cout << "\"14\" - Alcohol" << endl;
	cout << "\"15\" - Shoes" << endl;
	cout << "\"16\" - Kid's Clothing" << endl;
	cout << "\"17\" - Arts & Crafts" << endl;
	cout << "\"18\" - Home/Furniture" << endl;
	cout << "\"19\" - Auto" << endl;
	cout << "\"20\" - Dairy" << endl;
	cout << "\"21\" - Toys" << endl;
	cout << "\"22\" - Sports" << endl; */
	cout << "****************************" << endl;
}


