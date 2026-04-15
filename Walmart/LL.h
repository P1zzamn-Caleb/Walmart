#ifndef _LL_H
#define _LL_H

class Node
{
	int weight;
	Node* next;
public:
	Node() : weight(0), next(nullptr) {};
	Node(int w) : weight(w), next(nullptr) {};

	friend class LL;
};

class LL
{
	Node* root;
public:
	LL() :root(nullptr) {};

};

class adjacencyList
{
	int size;
public:
	//adjacencyList(int s): size(s)
};


#endif
