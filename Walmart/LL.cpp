
#include "LL.h"

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
