#include <iostream>
#include <fstream>

#include "LL.h"

using namespace std;
const string FILE_NAME = "ScooterWeights.txt";

int main() {
	ifstream graphData;
	int numVertices = 0, thisVertice =-1, 
		connectionWeight =-1, connectionVertice =0;
	

	graphData.open(FILE_NAME);
	if (!graphData.is_open())
	{
		cout << FILE_NAME << ": Error opening file." << endl;
		return 1;
	}

	cout << "WELCOME TO OUR WEIGHTED GRAPH THROUGH WALMART!" << endl;
	cout << "How many vertices do you have?" << endl;
	graphData >> numVertices;

	LL* vertices = new LL[numVertices];
	for (int i = 0; i < numVertices;i++)
	{
		graphData >> thisVertice;
		while (true)
		{

			graphData >> connectionVertice;
			if (connectionVertice == -1) break;
			graphData >> connectionWeight;
			vertices[thisVertice].Insert(connectionWeight, connectionVertice);
		}
	}

	graphData.close();
	for (int j = 0; j < numVertices;j++)
	{
		cout << j << " ";
		vertices[j].Print();
		cout << endl;
	}
		

	return 0;
}
