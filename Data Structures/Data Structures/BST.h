#pragma once
#ifndef BST_H
#define BST_H



class BST_NODE {
private:
	int _data;
	BST_NODE * _right;
	BST_NODE * _left;
public:
	BST_NODE(int data)
	{
		_data = data;
		_left = nullptr;
		_right = nullptr;
	}

	void insert(int val)
	{
		if (val >= this->_data) // go right
		{
			if (this->_right != nullptr)
			{
				this->_right->insert(val);
			}
			else
			{
				BST_NODE* new_node = new BST_NODE(val);
				this->_right = new_node;
			}
		}
		if (val <= this->_data) // go right
		{
			if (this->_left != nullptr)
			{
				this->_left->insert(val);
			}
			else
			{
				BST_NODE* new_node = new BST_NODE(val);
				this->_left = new_node;
			}
		}
	}

	void preOrder()
	{
		if (this != nullptr) {
			cout << this->_data << " ";
			this->_left->preOrder();
			this->_right->preOrder();
		}
	}
	void postOrderTraversal()
	{


	}

	void inOrderTraversal()
	{

	}


};





#endif // !BST_H
