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

	myLL1.insertValEnd(10);
	myLL1.insertValEnd(3);
	myLL1.insertValEnd(5);
	myLL1.insertValEnd(4);
	myLL1.insertVal(15);

	myLL2.insertValEnd(10);
	myLL2.insertValEnd(3);
	myLL2.insertValEnd(5);
	myLL2.insertValEnd(4);
	myLL2.insertVal(10);

	cout << (myLL1 == myLL2) << endl;
	//myLL.insertAtPosition(33, 0);
	
	/*myLL.Print();
	myLL.Delete(2);
	cout << "Deletion at element 2" << endl;
	myLL.Print();*/
	/*myLL.reverse();
	cout << "Reversed" << endl;
	myLL.Print();*/
	//system("pause");

	/*myBST.insert(5);
	myBST.insert(15);
	myBST.insert(8);
	myBST.insert(1);
	myBST.insert(13);

	myBST.preOrder();*/

	return 0;
}