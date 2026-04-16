//********************************************************************************
// Author: Caleb Ellis (Reviewed and Editted by Chloe Byrd)
// Name: Remove
// Purpose: Removes e
// Incoming: int e
// Outgoing: updated LL, true or false based on if it is successful or unsuccessful
// Return: true or false based on if it is successful or unsuccessful
//********************************************************************************
#include "LL.h"

bool LL::Remove(int e)
{
	bool removed = false;
	if (head == nullptr)
	{
	}
	else if (head->weight == e)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
		removed = true;
	}
	else
	{
		Node* curr = head;
		Node* prev = head;
		while (curr->next != nullptr && curr->weight != e)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr->weight == e)
		{
			prev->next = curr->next;
			delete curr;
			curr = nullptr;
			removed = true;
		}
	}
	return removed;
}
//********************************************************************************
// Author: Caleb Ellis
// Name: Search
// Purpose: Searches for e
// Incoming: weight e
// Outgoing: true or false based on if it is found
// Return: true or false based on if it is found
//********************************************************************************
bool LL::Search(int e)const
{
	bool found = false;
	if (head != nullptr)
	{
		Node* curr = head;
		while (curr->weight != e && curr->next != nullptr)
		{
			curr = curr->next;
		}
		if (curr->weight == e)
			found = true;
	}
	return found;
}

//********************************************************************************
// Author: Caleb Ellis
// Name: InsertAtFront
// Purpose: Inserts at the front of the LL
// Incoming: int e
// Outgoing: updated LL
// Return: none
//********************************************************************************
void LL::InsertAtFront(int e)
{
	head = new Node(e, head);
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
		cout << temp->weight << " ";
		temp = temp->next;
	}
}