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

//template <typename T>;

struct Node
{
	int data;
	struct Node *next;

	/*bool operator < (const Node& Node2)
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
	}*/
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
		//Node * head = new Node;
		_head = node;
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

		new_node->next = nullptr;
		new_node->data = data;

		if (h == nullptr) //linked list is empty
		{
			_head = new_node;
		}
		if (index == 0) //insert at head
		{
			new_node->next = _head;
			_head = new_node;
		}
		else
		{
			while (ind_node != nullptr)
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

	void ReversePrint() //This function worked on hackerrank because in hackerrank the node is the class for the LL
						//so the functions could be called on the nodes themselves. So the recursive call in the else statement
						// "ReversePrint(head->next); was a legitament call. Not sure how to implement it this way because 
						//head->next does not contain the function "ReversePrint" only a linked list does.
	{
		Node *head = _head;
		if (head->next == nullptr) //reached the end of the LL
		{
			cout << head->data << endl;;
			return;
		}
		else
		{
			//ReversePrint(head->next);
			cout << head->data << endl;
		}
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

	int GetNodeFromHead(int position)
	{
		Node * h = new Node;
		h = _head;
		while (position != 0)
		{
			h = h->next;
			position--;
		}
		return h->data;
	}

	int GetNodeFromTail(int position)
	{
		LinkedList revList(_head);
		revList.reverse();
		return revList.GetNodeFromHead(position);
	}

	int GoodGetNodeFromTail(int position)
	{
		Node * slow = _head;
		Node * fast = _head;

		for (int i = 0; i < position; i++)
		{
			fast = fast->next;
		}

		while (fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next;
		}
		//now fast is at the end of the list, so slow is "position" elements away from the end of the list
		int val = slow->data;

		return val;
	}

	void DeleteRepeat()//Given a sorted linked list it will delete the repeated elements
	{
		Node * temp = new Node;
		Node * h = new Node;
		Node * iter = new Node;
		h = _head;
		iter = _head;
		while (iter->next != nullptr)
		{
			if (iter->data == iter->next->data) //values are the same
			{
				temp = iter->next;
				if (temp->next != nullptr)
				{
					while (iter->data == temp->next->data)
					{
						temp = temp->next;
					}
				}
				iter->next = temp->next;
			}
			iter = iter->next;
		}
		_head = h;
	}

	bool operator == (const LinkedList& LL2)
	{
		Node * LL1_head = new Node;
		Node * LL2_head = new Node;
		LL1_head = this->_head;
		LL2_head = LL2._head;
		while (LL1_head == LL2_head)
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

void testLL()
{
	//BST_NODE myBST(10);
	LinkedList myLL1;
	LinkedList myLL2;

	cout << "We will initialize two Linked Lists, LL1 and LL2 " << endl;
	cout << "First we have LL1" << endl;

	myLL1.insertVal(10);
	myLL1.insertVal(9);
	myLL1.insertVal(6);
	myLL1.insertVal(2);
	myLL1.insertVal(2);

	myLL1.Print();

	cout << "Next we have LL2" << endl;

	myLL2.insertVal(15);
	myLL2.insertVal(12);
	myLL2.insertVal(5);
	myLL2.insertVal(2);
	myLL2.insertVal(1);

	myLL2.Print();

	cout << "We can get to any element from the front or back" << endl;
	cout << "The element at the first 'index' in LL1 is: " << myLL1.GetNodeFromHead(1) << endl;
	cout << "The element at the second 'index' from the end in LL1 is: " << myLL1.GoodGetNodeFromTail(2) << endl;

	//cout << "We can also insert values at given 'indexes'. We will insert 33 at postion 2 in LL1" << endl;
	//myLL1.insertAtPosition(8, 2);
	//myLL1.Print();

	cout << "By overloading the operator '==', we can test Linked List equivalence" << endl;
	cout << (myLL1 == myLL2) << endl;

	cout << "Next we will merge the sortedlinked lists into a new sorted Linked List" << endl;
	LinkedList Merged;
	Merged = MergeSorted(myLL1, myLL2);
	Merged.Print();

	cout << "Now we can delete the repeats in the sorted merged Linked Lists" << endl;
	Merged.DeleteRepeat();
	Merged.Print();


	cout << "We can also delete from the linked list. We will delete the element at 'index' 2 in the merged lists" << endl;
	Merged.Delete(2);
	Merged.Print();

	cout << "Now we will reverse the merged Linked list" << endl;
	Merged.reverse();
	Merged.Print();
}





#endif // !LINKEDLIST_H

