#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H


struct DoubleNode {
	DoubleNode * _next;
	DoubleNode * _prev;
	int _data;
};


class DoubleLinkedList
{
private:
	DoubleNode * _head;
public:
	DoubleLinkedList()
	{
		DoubleNode * head = new DoubleNode;
		head->_next = nullptr;
		head->_prev = nullptr;
		head->_data = 0;
		_head = head;
	}
	DoubleLinkedList(int data)
	{
		DoubleNode * head = new DoubleNode;
		head->_next = nullptr;
		head->_prev = nullptr;
		head->_data = data;
		_head = head;
	}
	DoubleNode * get_head()
	{
		return _head;
	}
	void print()
	{
		DoubleNode * temp = _head;
		while (temp->_next != nullptr)
		{
			cout << temp->_data << " ";
			temp = temp->_next;
		}
		cout << temp->_data << " ";
	}
	void insertVal(int data)
	{
		DoubleNode * new_node = new DoubleNode;
		new_node->_data = data;
		new_node->_next = _head;
		_head->_prev = new_node;
		_head = new_node;
	}
	void insertatTail(int data)
	{
		DoubleNode * new_node = new DoubleNode;
		new_node->_data = data;
		new_node->_next = nullptr;
		DoubleNode * temp = new DoubleNode;
		temp = _head;
		while (temp->_next != nullptr)
		{
			temp = temp->_next;
		}
		temp->_next = new_node;
		new_node->_prev = temp;
		return;
	}

	DoubleNode* remove_from_head()
	{
		DoubleNode * new_head = new DoubleNode;
		DoubleNode * returned = new DoubleNode;
		new_head = _head->_next;
		returned = _head;
		returned->_next = nullptr;
		_head = new_head;
		return returned;
	}

	DoubleNode* remove_from_tail()
	{
		DoubleNode * temp = new DoubleNode;
		DoubleNode * return_node = new DoubleNode;
		temp = _head;
		while (temp->_next->_next != nullptr)
		{
			temp = temp->_next;
		}
		return_node = temp->_next;
		temp->_next = nullptr;
		return return_node;
	}


};

void testDLL()
{
	DoubleLinkedList myDLL(5);
	myDLL.insertVal(4);
	myDLL.insertVal(8);
	myDLL.insertVal(10);
	myDLL.insertatTail(100);
	myDLL.print();
	myDLL.remove_from_head();
	DoubleNode * temp = myDLL.remove_from_tail();
	myDLL.print();
	//_int16 num = 0;
	//cout << sizeof(num) << endl;

	return;
}




#endif