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


vector<int> googletest()
{
	cout << "OMGGOOGLE" << endl;
	vector<int> result = {};
	vector<int> A = { -1,3,-4, 5,1,-6, 2,1 };

	int equi = -1; //equilibrium value
	int sum_left = 0; //this will hold the sum of all the numbers left of the index
	int sum_right = 0; // "" right of the index

	for (int j = 1; j < A.size(); j++)
	{
		sum_right += A[j];
	}
	if (sum_left == sum_right)//
	{
		result.push_back(0);
	}


	for (int i = 1; i < A.size(); i++)
	{
		sum_left += A[i-1];
		sum_right -= A[i];
		if (sum_left == sum_right) //we've reached the equilibrium
		{
			result.push_back(i);
		}
	}
	if (result.empty())
	{
		result.push_back(-1);
	}
	return result;

}


string solution(string &S, int K) {

	int current_substr = 0;
	char temp = ' ';
	
	for (int j = 0; j < S.size(); j++) //to save a little headache
	{
		if (S[j] >= 97 && S[j] <= 122) //lower
		{
			S[j] = S[j] - 32;
		}
	}
	
	for (int i = S.size()-1; i >= 0; i--)
	{
		if (S[i] == '-')
		{
			if (i == 0)//'-' has bubbled up to the front
			{
				for (int k = 0; k < S.size() - 1; k++)//kind of a gross solution. I'll come back to fix it if I have time
				{
					S[k] = S[k + 1];
				}
				S.resize(S.size() - 1);
			}
			//cout << "Dash" << endl;
			else if (current_substr < K) //the sublist is not the correct length
			{
				temp = S[i];
				S[i] = S[i - 1];
				S[i - 1] = temp; //bubbles the '-' backwards
				current_substr += 1;
			}
			else if (current_substr > K)//the substring has grown longer than it should have
				//and the dash needs to be bubbled right
			{
				int t = i;
				while (current_substr > K)
				{
					temp = S[t];
					S[t] = S[t + 1];
					S[t + 1] = temp;
					current_substr--;
				}
			}

			else
			{
				current_substr = 0; //resetting the substring because we've completed one set
			}
		}
		else if (S[i] >= 65 && S[i] <= 90) //upper
		{
			//cout << "upper" << endl;
			current_substr += 1;
		}
		else //number
		{
			//cout << "#" <<endl;
			current_substr += 1;
		}
		

	}

	return S;

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

