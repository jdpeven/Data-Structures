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

	bool operator < (const Node& Node2)
	{
		if (this->data < Node2.data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator <= (const Node& Node2)
	{
		if (this->data <= Node2.data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator > (const Node& Node2)
	{
		if (this->data > Node2.data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator >= (const Node& Node2)
	{
		if (this->data >= Node2.data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator == (const Node& Node2)
	{
		if (this->data == Node2.data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
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
	Node * get_head()
	{
		return _head;
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

	void Delete(int index)
	{
		Node * iter_node = new Node;
		iter_node = _head;
		if (index == 0) //delete head
		{
			_head = _head->next;
			return;
		}
		else
		{
			while (index != 1)
			{
				iter_node = iter_node->next;
				index--;
			}
			//Now at the node to delete
			iter_node->next = iter_node->next->next;
		}
	}

	void printInReverse()
	{

	}

	void insertNodeEnd(Node * new_node)
	{
		if (_head == nullptr)
		{
			_head = new_node;
			return;
		}
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

	bool operator ==(const LinkedList& LL2)
	{
		Node * LL1_head = new Node;
		Node * LL2_head = new Node;
		LL1_head = this->_head;
		LL2_head = LL2._head;
		while(LL1_head == LL2_head)
		{
			if (LL1_head->next == nullptr && LL2_head->next == nullptr)
			{
				return true;
			}
			else
			{
				LL1_head = LL1_head->next;
				LL2_head = LL2_head->next;
			}
		}
		return false;
	}



};
LinkedList MergeSorted(LinkedList LL1, LinkedList LL2)
{
	LinkedList new_LL;
	Node * head1 = new Node;
	Node * head2 = new Node;
	head1 = LL1.get_head();
	head2 = LL2.get_head();
	Node * temp = new Node;
	while (head1 != nullptr && head2 != nullptr) //both not empty
	{
		if (head1->data <= head2->data)//Used operator overloading in the Node struct
		{
			//must use temp otherwise when inserting the node, it would insert all the "next"
			temp = head1;
			head1 = head1->next;
			temp->next = nullptr;
			new_LL.insertNodeEnd(temp);
				
		}
		else if (head2->data < head1->data)
		{
			temp = head2;
			head2 = head2->next;
			temp->next = nullptr;
			new_LL.insertNodeEnd(temp);
		}
	}
	if (head1 == nullptr && head2 == nullptr)
	{
		return new_LL;
	}
	if (head1 == nullptr)//head1 is empty, head2 still has some
	{
		new_LL.insertNodeEnd(head2);
	}
	else if (head2 == nullptr)//head2 is empty, head1 still has some
	{
		new_LL.insertNodeEnd(head1);
	}
	return new_LL;
}







#endif // !LINKEDLIST_H

