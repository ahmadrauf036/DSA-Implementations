#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Stack {
protected:
	T* stackArray;
	int maxSize = 1000;
	int stackTop;
public:
	Stack()
	{
		stackArray = new T[maxSize];
		stackTop = -1;
	}
	void Push(T element)
	{
		if (!isFull()) {
			stackTop++;
			stackArray[stackTop] = element;
		}
		else
			cout << "Stack overflow." << endl;
	}
	T Pop() 
	{
		if(!empty())
		{
			T element = stackArray[stackTop];
			stackTop--;
			return element;
		}
		else
		{
			cout << "Stack underflow." << endl;
			return -1;
		} 
	}
	bool empty()const
	{
		return (stackTop == -1);
	}
	bool isFull()const
	{
		return (stackTop == maxSize - 1);
	}
	int top ()const
	{
		return stackTop;
	}
	
};

bool ValidExpression(string exp)
{
	Stack<char> a;
	for (int i = 0; exp[i]!=0; i++)
	{

		if (exp[i] == '(')
			a.Push(exp[i]);
		else if (exp[i] == ')')
		{
			if (a.empty())
				return false;
			a.Pop();
		}
	}
	if (a.empty())
		return true;
	return false;

}



int main()
{
	string e;
	cout << "Enter expression: ";
	getline(cin,e);
	if (ValidExpression(e))
		cout << "Expression is valid." << endl;
	else
		cout << "Invalid expression." << endl;

	return 0;

	
}