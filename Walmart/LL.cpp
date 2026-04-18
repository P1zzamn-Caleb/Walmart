
#include "LL.h"

//********************************************************************************
// Author: Tori Dean
// Name: getNext
// Purpose: Allows referenced access to the next data memeber of Node
// Incoming: none
// Outgoing: Node* next
// Return: Node* next
//********************************************************************************
Node* Node::getNext()const {
	return next;
}


//********************************************************************************
// Author: Tori Dean
// Name: getWeight
// Purpose: Allows referenced access to the weight data memeber of Node
// Incoming: none
// Outgoing: int weight
// Return: int weight
//********************************************************************************
int Node::getWeight()const {
	return weight;
}


//********************************************************************************
// Author: Tori Dean
// Name: getConnection
// Purpose: Allows referenced access to the connection data memeber of Node
// Incoming: none
// Outgoing: int connection
// Return: int connection
//********************************************************************************
int Node::getConnection()const {
	return connection;
}


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


//********************************************************************************
// Author: Tori Dean
// Name: getHead
// Purpose: Allows referenced access to the head data memeber of LL
// Incoming: none
// Outgoing: Node* head
// Return: Node* head
//********************************************************************************
Node* LL::getHead()const
{
	return head;
}

//********************************************************************************Name: ~LL
// Author: Tori Dean
// Name: ~LL
// Purpose: Frees memory for all dynamicaly allocated nodes in the linked list.
// Incoming: none
// Outgoing: none
// Return: none
//********************************************************************************LL::~LL() {
LL::~LL() {
	Node* current = head;
	while (current != nullptr) {
		Node* toDelete = current;
		current = current->next;
		delete toDelete;
	}
	head = nullptr;
}