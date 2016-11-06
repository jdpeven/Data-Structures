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
#include "HashTable.h"
#include "Extra.h"
#include "Queue.h"
#include "DoubleLinkedList.h"
#include "Sorting.h"


/*vector < string > missingWords(string s, string t) {
	int cur_t_index = 0;
	vector <string> s_1;
	int s_iter = 0;
	vector <string> t_1;
	int t_iter = 0;
	string new_string = "";

	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) != " ")
		{
			new_string += s[i];
		}
		else //end of string
		{
			s_1[s_iter] = new_string;
			new_string = ""; //reseting
			s_iter++;
		}
	}
	for (int i = 0; i < s_1.size(); i++)
	{
		cout << s_1[i];
	}
	return s_1;
}*/



int main(void)
{
	//testLL();
	//testExtra();
	//testHashTable();
	//testDLL();
	//testQueue();
	//testBST();
	testSorting();
	
	system("pause");

	return 0;
}



