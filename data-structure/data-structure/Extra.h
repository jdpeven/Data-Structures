#pragma once
#ifndef EXTRA_H
#define EXTRA_H

#include <stack>
#include <string>

//This header file will just have a lot of extra functions that aren't related to specific data structures

void reverse_string(string * str)
{
	int j = (*str).length() - 1;
	char temp;
	for (int i = 0; i <= j; i++, j--)
	{
		temp = (*str)[i];
		(*str)[i] = (*str)[j];
		(*str)[j] = temp;
	}
	return;
}

void left_rotate_array(int size, int rotation, int* arr)
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{

	}
	cout << endl;
}

vector<string> splitByDelimiter(string str, char del)
{
	vector<string> vect;
	string temp = "";
	int start = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == del)//reached the delimeter
		{
			temp = str.substr(start, i);//there's some weird error with substring....
			vect.push_back(temp);
			start = i + 1; //this should ideally skip over the delimiter
		}
	}
	return vect;

}


int myAtoi(string str)
{
	/*for (int i = 0; i < str.length(); i++)
	{

	}*/
	return 0;
}

void reverse_string_XOR_ptr(string *str)
{
	char * a = &((*str)[0]);
	int length = (*str).length();
	char * b = &((*str)[length - 1]);

	while (a <= b)
	{
		*a = *a ^ *b;
		*b = *b ^ *a;
		*a = *a ^ *b;
		a++;
		b--;
	}

	return;
}

void reverse_string_XOR(string *str)
{
	int a = 0;
	int b = (*str).length() - 1;

	while (a <= b)
	{
		(*str)[a] = (*str)[a] ^ (*str)[b];
		(*str)[b] = (*str)[b] ^ (*str)[a];
		(*str)[a] = (*str)[a] ^ (*str)[a];
		a++;
		b--;
	}

	return;
}



bool parenthesis_pair(string str)
{
	return true;
}

int return_non_pair(vector<int> list)
{
	return 0;
}

/*void permute(char *a, int l, int r)
{
int i;
if (l == r)
printf("%s\n", a);
else
{
for (i = l; i <= r; i++)
{
swap((a + l), (a + i));
permute(a, l + 1, r);
swap((a + l), (a + i)); //backtrack
}
}
}*/

vector<int> specific_subset(int i, vector<int> list)
{
	vector<int> subset;
	for (int j = 0; j < i; j++)
	{
		if (i & j)
		{
			subset.push_back(list[j]);
		}
	}
	return subset;
}


void subset(vector<int> list, vector<vector<int>> * total)
{
	for (int i = 0; i < (2 ^ (list.size())); i++)
	{
		total->push_back(specific_subset(i, list));
	}
}


bool is_balanced(string expression) {
	stack<char> mystack;
	char top;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '(')
		{
			mystack.push(expression[i]);
		}
		else if (expression[i] == '{')
		{
			mystack.push(expression[i]);
		}
		else if (expression[i] == '[')
		{
			mystack.push(expression[i]);
		}
		else if (expression[i] == ')')
		{
			top = mystack.top();
			mystack.pop();
			if (top != '(')
			{
				return false;
			}
		}
		else if (expression[i] == '}')
		{
			top = mystack.top();
			mystack.pop();
			if (top != '{')
			{
				return false;
			}
		}
		else if (expression[i] == ']')
		{
			top = mystack.top();
			mystack.pop();
			if (top != '[')
			{
				return false;
			}
		}
	}
	return true;
}




void testExtra()
{
	/*cout << "First we will reverse a string" << endl;
	string str1 = "Hello Friend";
	string str2 = "Hello Friend";
	string str3 = "Hello Friend";

	reverse_string(&str1);
	cout << str1 << endl;
	reverse_string_XOR_ptr(&str2);
	cout << str2 << endl;*/
	//int my_arr[5] = { 1, 2, 3, 4, 5 };
	//left_rotate_array(5, 2, my_arr);
	//reverse_string_XOR(&str3);
	//cout << str3 << endl;



	/* Driver program to test above functions */
	/*char str[] = "ABC";
	int n = strlen(str);
	permute(str, 0, n - 1);

	vector<string> result;
	result = splitByDelimiter("Hello, good, friend, adam", ',');
	for (int i = 0; i < result.size(); i++)
	{
	cout << result[i] << endl;
	}*/

	/*vector<int> mylist = { 1,2,3 };
	vector<vector<int>> subsets = {};

	subset(mylist, &subsets);

	for (int i = 0; i < subsets.size(); i++)
	{
	for (int j = 0; j < subsets[i][j]; j++)
	{
	cout << subsets[i][j] << endl;
	}
	cout << endl;
	}*/
	/*vector<int> res = {};
	res = googletest();
	for (int i = 0; i < res.size(); i++)
	{
	cout << res[i] << endl;
	}*/

	//string sample = "2-4A0r7-4k";
	//string sample = "2-4A0r7-4k";
	/*string sample = "r";

	cout << sample << endl;
	string sol = solution(sample, 3);
	cout << sol << endl;
	*/

	//char ch = 'A';


	//cout << 'A' << int('A') << " Z" << int('Z') << " a" << int('a') << " z" << int('z');


	cout << is_balanced("[({}())]") << endl;



	return;
}





#endif // !EXTRA_H

