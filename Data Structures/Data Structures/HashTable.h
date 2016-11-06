#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
/*
class BasicClass
{
private:
	int _index;
	string _name;
	static int _instances;
public:
	BasicClass()
	{
		_index = _instances;
		_name = to_string(_instances);
		_instances++;
	}
	BasicClass(int num, string name)
	{
		_index = num;
		_name = name;
		_instances++;
	}
	BasicClass(string name)
	{
		_index = _instances;
		_name = name;
		_instances++;
	}
	int get_index()
	{
		return _index;
	}
	string get_name()
	{
		return _name;
	}

};



class HashTable
{
private:
	int _size; //this will be how large my hash table will be
	LinkedList* _table; //Here the hash table is implemented as an array of linked lists
	int _elements; //this will be how many elements are currently stored in the table
public:
	HashTable()
	{
		_size = 13;
		_table = new LinkedList[_size];
		_elements = 0;
	}
	/*void initTable()
	{
		for (int i = 0; i < _size; i++)
		{
			_table[i] = null;
		}
	}*/
/*
	HashTable(int size)
	{
		_size = size;
		_table = new (nothrow) LinkedList[size];
		_elements = 0;
	}
	int get_size()
	{
		return _size;
	}
	int get_elements()
	{
		return _elements;
	}
	int get_hash(int val)//this will return the index of the array that the element should be stored at
		//the val is passed in because different classes/strings/ints will be generated seperately
		//for example a string may have "val" calculated by "adding up" all the elements of the string,
		//whereas an integer may be cubed to generate the val
	{
		return val % _size;
	}
	void insert(int num)
	{
		int hash = 0;
		hash = get_hash(num * num * num);
		_table[hash].insertVal(num);
		_elements += 1;
	}
	void insert(BasicClass basic)
	{
		/*int hash = 0;
		hash = get_hash(basic.get_index() ^ 3);
		//_table[hash].insertVal(basic.get_name());*/

/*
	}
	bool resize()
	{
		if (_elements > (0.7) * _size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	


};

void testHashTable()
{
	BasicClass example1("John");
	BasicClass example2("James");
	BasicClass example3("Anna");
	BasicClass examples4("James");
	HashTable ht(13);
	ht.insert(example1);
	//cout << ht.get_size() << endl;
	//cout << ht.get_elements() << endl;
	//ht.insert(45);
	//cout << ht.get_elements() << endl;
}
*/


#endif