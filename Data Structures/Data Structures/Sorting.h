#ifndef SORTING_H
#define SORTING_H

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


int partition(vector<int> *list, int low, int high)
{
	int pivot = (*list)[high];
	int wall = low;
	int temp = 0;
	for (int i = 0; i < (*list).size(); i++)
	{
		if ((*list)[i] < pivot)
		{
			temp = (*list)[i];
			(*list)[i] = (*list)[wall];
			(*list)[wall] = temp;
			wall++;
		}
	}
	temp = (*list)[wall];
	(*list)[wall] = (*list)[pivot];
	(*list)[pivot] = temp;
	return wall;
}


void quicksort(vector<int>* list, int low, int high)
{
	int p = 0;
	if (low < high)
	{
		p = partition(list, low, high);
		quicksort(list, low, p - 1);
		quicksort(list, p + 1, high);
	}
}



void testSorting()
{
	vector<int> list = { 1,2,8,5,2,0,3,9 };
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << endl;
	}
	cout << endl << endl;
	quicksort(&list, 0, list.size());
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << endl;
	}




	return;
}








#endif
