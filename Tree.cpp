#include "stdafx.h"
#include <fstream>
#include <clocale>
#include <iostream>
using namespace std;


struct TNode;
typedef TNode * PTNode;
struct TNode
{
	PTNode left, right;
	int val;
};
PTNode root;
int counter = 0;
TNode arr[1000];
void append(PTNode v, int value)
{
	if (value > v->val)
	{
		v->right = &arr[counter + 1];
		arr[counter + 1].val = value;
		arr[counter + 1].left = nullptr;
		arr[counter + 1].right = nullptr;
		++counter;
	}
	else if (value < v->val)
	{
		v->left = &arr[counter + 1];
		arr[counter + 1].val = value;
		arr[counter + 1].left = nullptr;
		arr[counter + 1].right = nullptr;
		++counter;
	}
}
void add(PTNode v, int value)
{
	if (value >= (*v).val)
	{
	  if (v->right == nullptr)
		{
			append(v, value);
			cout << "Right son -> " << value << endl;
			return ;
		}
		else
		{
			add(v->right, value);
			return ;
		}
	}
	else if (value <= (*v).val)
	{
		if (v->left == nullptr)
		{
			append(v, value);
			cout << "Left son -> " << value << endl;
			return ;
		}
		else
		{
			add(v->left, value);
			return ;
		}
	}
}
int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "rus");
	int k;
	root = &arr[1];
	root->left = nullptr;
	root->right = nullptr;
	cout << "Enter start value of root: " << endl;
	cin >> root->val;
	counter = 1;
	system("cls");
	cout << "Root -> " << root->val << endl;
	ifstream input("input.txt");
	int i = 0;
	while (!input.eof())
	{
		input >> k;
		//arr[i].val = k;
		add(root, k);
		i++;
	}
	system("pause");
	return 0;
}
