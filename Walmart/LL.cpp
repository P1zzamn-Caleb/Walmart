//********************************************************************************
// Author: Caleb Ellis (Reviewed and Editted by Chloe Byrd)
// Name: Remove
// Purpose: Removes e
// Incoming: int e
// Outgoing: updated LL, true or false based on if it is successful or unsuccessful
// Return: true or false based on if it is successful or unsuccessful
//********************************************************************************
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
	if (head == nullptr || e < head->weight) //2 cases where head could change
		head = new Node(e, c, head);
	else {                                   //insert in the middle or at the end
		//loop to get to the insertion point
		Node* prev = head;
		Node* current = head;
		while (current != nullptr && e > current->weight) { 
			prev = current;
			current = current->next;
		}
		//code to actually create a new Node and set pointers accurately
		if (current != nullptr && e == current->weight)
			cout << "NO DUPES" << endl;
		else
			prev->next = new Node(e, c, current);
	}
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

	while (temp != nullptr)
	{
		cout << temp->connection << " " << temp->weight << " ";
		temp = temp->next;
	}
}
