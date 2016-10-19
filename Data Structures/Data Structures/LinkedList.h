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
	Node * head;
public:
	LinkedList(int data)
	{
		Node * head = new Node;
		head->data = data;
		head->next = nullptr;
	}
	LinkedList(Node * node)
	{
		Node * head = new Node;
		head = node;
	}
	void Print()
	{
		while (head != nullptr)
		{
			cout << head->data << endl;
			head = head->next;
		}
	}

	void insertValEnd(int data)
	{
		Node * new_node = new Node;
		new_node->data = data;
		new_node->next = nullptr;
		Node * iter = head;

		while (iter->next != nullptr)
		{
			iter = iter->next;
		}
		iter->next = new_node;
		return;
	}

	void insertNodeEnd(Node * new_node)
	{
		Node * iter = head;
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}
		iter->next = new_node;
		return;
	}



};




#endif // !LINKEDLIST_H

