#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;

//Here will be all the code for the linked list operations

struct Node
{
	int data;
	struct Node *next;
};

class LinkedList
{
private:
	Node * _head;
public:
	LinkedList(int data)
	{
		Node * head = new Node;
		head->data = data;
		head->next = nullptr;
		_head = head;
	}
	LinkedList(Node * node)
	{
		Node * head = new Node;
		head = node;
	}
	void Print()
	{
		Node* n = _head;
		while (n != nullptr)
		{
			cout << n->data << endl;
			n = n->next;
		}
	}
	void insertVal(int data)
	{
		Node * new_node = new Node;
		new_node->data = data;
		new_node->next = _head;
		_head = new_node;
	}

	void insertValEnd(int data)
	{
		Node * new_node = new Node;
		new_node->data = data;
		new_node->next = nullptr;
		Node * n = _head;

		while (n->next != nullptr)
		{
			n = n->next;
		}
		n->next = new_node;
		return;
	}

	void insertNodeEnd(Node * new_node)
	{
		Node * iter = _head;
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}
		iter->next = new_node;
		return;
	}

	void reverse()
	{
		Node *h = _head;
		Node *temp = nullptr;
		Node *cur = nullptr;
		while (h != nullptr)
		{
			temp = h->next;
			h->next = cur;
			cur = h;
			h = temp;
		}
		_head = cur;
		return;
	}



};




#endif // !LINKEDLIST_H

