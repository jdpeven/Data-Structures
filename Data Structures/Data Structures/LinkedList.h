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
	LinkedList()
	{
		Node* head = new Node;
		head = nullptr;
		_head = head;
	}
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
		Node * h = new Node;
		if (_head == nullptr)
		{
			h->next = nullptr;
			h->data = data;
			_head = h;
		}
		else
		{
			h = _head;
			while (h->next != nullptr)
			{
				h = h->next;
			}
			new_node->data = data;
			new_node->next = nullptr;
			h->next = new_node;

			return;
		}
	}

	void insertAtPosition(int data, int index)
	{
		Node * new_node = new Node;
		Node * h = new Node;
		Node * ind_node = new Node;
		Node * temp = new Node;
		h = _head; //This will be the constant pointer to the head of the list
		ind_node = _head; //This will be the one iterated through
		if (h == nullptr) //linked list is empty
		{
			h->next = nullptr;
			h->data = data;
			_head = h;
		}
		new_node->next = nullptr;
		new_node->data = data;
		if (index == 0) //insert at head
		{
			new_node->next = _head;
			_head = new_node;
		}
		else
		{
			while (h != nullptr)
			{
				if (index == 1) //reached the index
				{
					temp = ind_node->next;
					ind_node->next = new_node;
					new_node->next = temp;
					return;
				}
				else
				{
					ind_node = ind_node->next;
					index--;
				}
			}
		}
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

