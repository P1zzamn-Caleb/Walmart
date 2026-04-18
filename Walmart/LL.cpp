#include "LL.h"
#include "BinaryHeap.h"

//********************************************************************************
// Author: Caleb Ellis
// Name: InsertWeight
// Purpose: Inserts weights in order in LL
// Incoming: int e
// Outgoing: updated LL
// Return: none
//********************************************************************************
void LL::Insert(int e, int c) {
	head = new Node(e, c, head);
		
}


//********************************************************************************
// Author: Caleb Ellis
// Purpose: Prints LL
// Incoming: none
// Outgoing: none
// Return: none
//********************************************************************************
void LL::Print()const
{
	Node* temp = head;

	while (temp!=nullptr)
	{
		cout << temp->connection << " " << temp->weight << " ";
		temp = temp->next;
	}
}

void LL::insertWeights(BinaryHeap& heap, LL whoChangedObject)
{
	Node* temp = head;

	while (temp != nullptr)
	{
		heap.insert((temp->weight + whoChangedObject.distance), temp->connection);
		temp = temp->next;
	}

}

void LL::adjustDistance(int d, int who)
{
	if (d < distance || distance==0)
	{
		distance = d;
		whoChangedMe = who;
	}
	cout << distance << " d " << whoChangedMe << " w " << endl;
}

int LL::getWhoChangedMe()
{
	return whoChangedMe;
}
