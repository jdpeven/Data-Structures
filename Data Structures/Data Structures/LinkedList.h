#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Here will be all the code for the linked list operations

struct Node
{
	int data;
	struct Node *next;
}

void Print(Node *head)
{
	while (head != nullptr)
	{
		cout << head->data << endl;
		head = head->next;
	}
}





#endif // !LINKEDLIST_H

