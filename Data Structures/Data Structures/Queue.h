#ifndef QUEUE_H
#define QUEUE_H

#include "DoubleLinkedList.h"

class Queue : public DoubleLinkedList, public DoubleNode
{
private:
	DoubleLinkedList _queue;//this could be more efficient by using the DoubleNode first/last but it's simpler right
							//now to do it this way. With a constant pointer to the first and last node, enque and deque
							//would be a lot more efficient
	//DoubleNode first;
	//DoubleNode last;

public:
	Queue()
	{
		_queue = DoubleLinkedList();
	}
	Queue(int data)
	{
		_queue = DoubleLinkedList(data);
	}
	void print()
	{
		_queue.print();
		return;
	}
	void enqueue(int data)
	{
		_queue.insertVal(data);
	}
	DoubleNode * dequeue()
	{
		return _queue.remove_from_tail();
	}
};


void testQueue()
{
	Queue myqueue(5);
	myqueue.enqueue(6);
	myqueue.enqueue(7);
	myqueue.enqueue(8);
	myqueue.print();
	cout << "Deque: " <<  myqueue.dequeue()->_data << endl;

	return;
}





#endif