#include <iostream>
using namespace std;

char tree[10];

void setRoot(char data)
{
	if (tree[0] != 0)
	{
		cout << "Root is not empty." << endl;
		return;
	}
	tree[0] = data;
}

void setLeftChild(char data,int parent)
{
	if (tree[(parent * 2) + 1] == 0)
	{
		tree[(parent * 2) + 1] = data;
	}
	else
		cout << "Can't set left child of " << parent << endl;
}

void setRightChild(char data,int parent)
{
	if (tree[(parent * 2) + 2] == 0)
		tree[(parent * 2) + 2] = data;
	else
		cout << "Can't set right child of " << parent << endl;
}

void printTreeArray()
{
	for (int i = 0; i < 10; i++)
	{
		if (tree[i] == 0)
		{
			cout << "N" << " ";
			continue;
		}
		cout << tree[i] << " ";
	}
	cout << endl;
}
int main()
{
	setRoot('2');
	setLeftChild('9', 0);
	setRightChild('3', 0);
	setLeftChild('1', 2);
	setRightChild('4', 2);
	printTreeArray();
}