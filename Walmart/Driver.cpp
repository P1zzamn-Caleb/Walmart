//**************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
//Start Date: April 16, 2026
//Name: CS 355 Walmart Graph Assignment - Main Driver
//Description: This file is used as the driver program for the Walmart weighted 
//				graph navigation system. It reads graph data from a file, builds an 
//				adjacency list using linked lists, displays the warehouse map and allows
//				user to find shortest paths between aisles using Dijkstra's algorithm.
//**************************************************************************************
#include <iostream>
#include <fstream>
#include "LL.h"
#include "Dijkstra.h"

using namespace std;
const string FILE_NAME = "ScooterWeights.txt";
//*************************************************************************************
//Author: Jay Goodroe, Chloe Byrd, Tori Dean, Caleb Ellis
//Name: Main (Driver - Walmart Weighted Graph Navigation System)
//Purpose: Entry point of program. Loads graph from file, builds
//			adjacency list, displays graph structure, and allows
//			user to input start/end nodes for shortest path navigation.
//Incoming: File input (ScooterWeights.txt), user input (start/end aisles)
//Outgoing: Displays graph structure and navigation results
//Return: 	int (program exit result)
//*************************************************************************************
void LocationsMenu();

int main() {
	string names[] = {
	"Entrance",
	"Bread",
	"Produce",
	"Checkout",
	"Dairy",
	"Toys",
	"Sports",
	"Auto",
	"Clothing",
	"Health",
	"Personal Care",
	"Frozen",
	"Kitchen",
	"Garden",
	"Deli",
	"Shoes",
	"Kids Clothing",
	"Arts & Crafts",
	"Home",
	"Party",
	"Electronics",
	"Unknown"
	};

	ifstream graphData;
	
	int numVertices = 0, 
	thisVertice = -1, 
	connectionWeight = -1, 
	connectionVertice = 0, // connection is an int for this implementation
	startVertice = 0, 
	endVertice = 0;

//**************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
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
		return 1;
	}

//**************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
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
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
//Name: ReadVertexCount
//Purpose: Reads number of vertices from input file
//Incoming: file stream
//Outgoing: numVertices updated
//Return: none
//**************************************************************************************
	graphData >> numVertices;
	cout << "Total aisles (vertices): " << numVertices << endl << endl;

//**************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
//Name: InitializeGraph
//Purpose: Creates array of linked lists for adjacency representation 
//Incoming: numVertices
//Outgoing: dynamic LL array created
//Return: none
//**************************************************************************************
	LL<int>* vertices = new LL<int>[numVertices];

//**************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
//Name: BuildAdjacencyList
//Purpose: Reads file and forms adjacency list graph
//Incoming: file stream data
//Outgoing: populated linked list graph structure
//Return: none
//**************************************************************************************
	for (int i = 0; i < numVertices; i++)
	{
		graphData >> thisVertice;
		cout << "Processing Aisle " << thisVertice << endl;
		
		while (true)
		{
			graphData >> connectionVertice;
			
			if (connectionVertice == -1) {
				cout << " End of connections for Aisle " << thisVertice << endl;
				break;
			}
			graphData >> connectionWeight;
			connectionWeight -= 30;
			vertices[thisVertice].Insert(connectionWeight, connectionVertice);

			cout << " Connected to Aisle " << connectionVertice << " | Weight: " << connectionWeight << endl;
		}
		cout << endl;
	}
	graphData.close();	

//**************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
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
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
//Name: UserNavigationMenu
//Purpose: Allows user to input start and end aisles for navigation
//Incoming: user input (start, end, choice)
//Outgoing: Display navigation process (placeholder for shortest path)
//Return: none
//**************************************************************************************
	int start, end;
	char choice;

	cout << endl << "========================================" << endl;
	cout << "         NAVIGATION MENU" << endl;
	cout << "========================================" << endl;

	cout << "Available aisles: 0 to " << numVertices - 1 << endl;

	do {
		LocationsMenu(); // optional but GOOD for demo

		cout << endl << "Enter starting aisle: ";
		cin >> start;

		cout << "Enter destination aisle: ";
		cin >> end;

		cout << endl << "Finding shortest path..." << endl;

		dijkstra(vertices, numVertices, start, end);

		cout << endl << "Try another route? (y/n): ";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');

//**************************************************************************************
//
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

//**************************************************************************************
//Author: Chloe Byrd, Caleb Ellis, Tori Dean, Jay Goodroe
//Name: LocationsMenu
//Purpose: Displays all available aisle options for user selection
//Incoming: none
//Outgoing: Console output (list of aisle options)
//Return: none
//**************************************************************************************
void LocationsMenu()
{
	cout << endl << "****************************" << endl;
	cout << "Location Options:" << endl;
	cout << "\"0\" - Entrance" << endl;
	cout << "\"1\" - Bread" << endl;
	cout << "\"2\" - Produce" << endl;
	cout << "\"3\" - Checkout" << endl;
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
	cout << "\"22\" - Sports" << endl;
	cout << "****************************" << endl;
}


