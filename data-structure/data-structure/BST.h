#pragma once
#ifndef BST_H
#define BST_H

#include <stack>
#include <queue>

class BST_NODE {
public:
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
	BST_NODE()
	{
		_data = 0;
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
	void postOrder()
	{
		if (this != nullptr)
		{
			this->_left->postOrder();
			this->_right->postOrder();
			cout << this->_data << " ";
		}
	}

	void topView()//this works by printing only what you would see from the top looking down
				  //so       8
				  //		  / \
				  		//		 4   14
//		/ \  / \
		//	   1   5 9  20
//would print 1-4-8-14-20
	{
		stack<BST_NODE*> mystack;
		printLeft(this->_left, &mystack);
		queue<BST_NODE*> myqueue;
		printRight(this->_right, &myqueue);

		int stacksize = mystack.size();
		for (int i = 0; i < stacksize; i++)//originally it was "; i < mystack.size();" but because I was
										   //popping values off the stack, the size kept changing, messing with my iterator
		{
			cout << mystack.top()->_data << " ";
			mystack.pop();
		}
		cout << _data << " ";
		int queuesize = myqueue.size();
		for (int j = 0; j < queuesize; j++)
		{
			cout << myqueue.front()->_data << " ";
			myqueue.pop();
		}
		cout << endl;

		return;
	}
	void printLeft(BST_NODE * node, stack<BST_NODE*> *mystack)
	{
		(*mystack).push(node);
		if (node->_left != nullptr)
		{
			printLeft(node->_left, mystack);
		}
		return;
	}

	void printRight(BST_NODE * node, queue<BST_NODE*> *myqueue)
	{
		(*myqueue).push(node);
		if (node->_right != nullptr)
		{
			printRight(node->_right, myqueue);
		}
		return;
	}

	void inOrderTraversal()
	{

	}

	void levelOrderTraversal()
	{
		vector<BST_NODE*> myvect;
		queue<BST_NODE*> myqueue;
		BST_NODE* current = new BST_NODE;
		myqueue.push(this);
		while (!myqueue.empty())
		{
			current = myqueue.front();
			myqueue.pop();
			if (current->_left != nullptr)
			{
				myqueue.push(current->_left);
			}
			if (current->_right != nullptr)
			{
				myqueue.push(current->_right);
			}
			//cout << current->_data << endl;
			myvect.push_back(current);
		}
		for (int i = 0; i < myvect.size(); i++)
		{
			cout << myvect[i]->_data << " ";
		}


	}






};

/*int solution(int A, int B, tree*T)
{
int result = 0;
if (T->x < A || T->x >B)//if a node is less than the min or greater than the max,
//then none of it's children can fit in the range so we should just return
{
return 0;
}
else//T is in the range [A,B], and now we will find the largest subtree
{
if (T->l == nullptr && T->r == nullptr) //leaf
{
return 1; // we already know that this node is within [A,B] so we will return
//1 rather than zero, but with no recursive call
}
else if (T->l == nullptr && T->r != nullptr) //only has a right side
{
return 1 + solution(A, B, T->r);
}
else if (T->l != nullptr && T->r == nullptr)
{
return 1 + solution(A, B, T->l);
}
else
{
int left_result = solution(A, B, T->l);
int right_result = solution(A, B, T->r);

if (left_result >= right_result)
{
return 1 + left_result;
}
else if (left_result < right_result)
{
return 1 + right_result;
}
else
{
cout << "you missed a test case" << endl;
}
}
}
}*/

void testBST()
{
	BST_NODE myBST(10);
	myBST.insert(5);
	myBST.insert(15);
	myBST.insert(8);
	myBST.insert(1);
	myBST.insert(13);

	myBST.levelOrderTraversal();
	//system("pause");

	//myBST.preOrder();
	//myBST.preOrder();
	//cout << endl;
	//myBST.postOrder();
	//cout << endl;

	//cout << "Top view" << endl;
	//myBST.topView();
	return;
}





#endif // !BST_H
