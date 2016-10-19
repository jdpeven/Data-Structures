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
	BST_NODE myBST(10);
	/*LinkedList myLL(0);

	myLL.insertValEnd(0);
	myLL.insertValEnd(3);
	myLL.insertValEnd(5);
	myLL.insertValEnd(4);

	myLL.Print();*/

	myBST.insert(5);
	myBST.insert(15);
	myBST.insert(8);
	myBST.insert(1);
	myBST.insert(13);

	myBST.preOrder();

	return 0;
}