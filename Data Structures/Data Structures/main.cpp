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

#include "LinkedList.h"
#include "BST.h"

int main(void)
{
	//BST_NODE myBST(10);
	LinkedList myLL1;
	LinkedList myLL2;

	myLL1.insertVal(10);
	myLL1.insertVal(9);
	myLL1.insertVal(8);
	myLL1.insertVal(6);
	myLL1.insertVal(2);

	myLL1.Print();

	/*cout << "The first position is " << myLL1.GetNodeFromHead(1) << endl;
	cout << "The first position from the end is " << myLL1.GetNodeFromTail(1) << endl;*/
	/*myLL2.insertVal(15);
	myLL2.insertVal(12);
	myLL2.insertVal(5);
	myLL2.insertVal(2);
	myLL2.insertVal(1);

	cout << "LL2" << endl;
	myLL2.Print();

	cout << "Merged" << endl;
	LinkedList Merged;
	Merged = MergeSorted(myLL1, myLL2);
	Merged.Print();
	*/
	//cout << (myLL1 == myLL2) << endl;
	//myLL.insertAtPosition(33, 0);
	
	/*myLL.Print();
	myLL.Delete(2);
	cout << "Deletion at element 2" << endl;
	myLL.Print();*/
	/*myLL.reverse();
	cout << "Reversed" << endl;
	myLL.Print();*/
	system("pause");

	/*myBST.insert(5);
	myBST.insert(15);
	myBST.insert(8);
	myBST.insert(1);
	myBST.insert(13);

	myBST.preOrder();*/

	return 0;
}