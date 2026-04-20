#include "LL.h"

//********************************************************************************
// Author: Caleb Ellis, Chloe Byrd, Tori Dean, and Jay Goodroe
// Name: Insert
// Purpose: Inserts weights in order in LL
// Incoming: int e
// Outgoing: updated LL
// Return: none
//********************************************************************************
void LL::Insert(int e, int c) {
	head = new Node(e, c, head);
		
}


//********************************************************************************
// Author: Caleb Ellis, Chloe Byrd, Tori Dean, and Jay Goodroe
// Name: Print
// Purpose: Traverses and displays all nodes in the linked list 
// Incoming: none
// Outgoing: Shows output of connections and weights
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
