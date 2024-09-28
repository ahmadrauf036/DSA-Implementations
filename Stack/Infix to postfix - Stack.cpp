
//INFIX TO POSTFIX

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
		if (!empty())
		{
			T element = stackArray[stackTop];
			stackTop--;
			return element;
		}
		else
		{
			cout << "Stack underflow." << endl;
			return T();
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
	int top()const
	{
		return stackArray[stackTop];
	}
	~Stack() {
		delete[] stackArray;
	}

};

int pres(char e1)
{
	if (e1 == '^')
		return 3;
	else if (e1 == '*' || e1 == '/' || e1 == '%')
		return 2;
	else if (e1 == '+' || e1 == '-')
		return 1;
	return 0;
}

string infix_to_postfix(string expression)
{
	Stack<char> st;
	string postfix_expression;
	for (int i = 0; expression[i]!=0; i++)
	{
		if (expression[i] == ' ')
			continue;
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			postfix_expression += expression[i];
			postfix_expression += ' ';
		}
		else if (expression[i] == '(')
			st.Push(expression[i]);
		else if (expression[i] == ')')
		{
			while (st.top() != '(')
			{
				if (st.empty())
				{
					cout << "Invalid Expression." << endl;
					return "0";
				}
				postfix_expression += st.Pop();
				postfix_expression += ' ';
			}
			st.Pop();
		}
		else if (expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-' || expression[i] == '^')
		{
			while(!st.empty())
			{
				if (pres(expression[i]) <= pres(st.top()))
				{
					postfix_expression += st.Pop();
					postfix_expression += ' ';
				}
				else
					break;
			}
			st.Push(expression[i]);
		}

	}
	while (!st.empty())
	{
		postfix_expression += st.Pop();
		postfix_expression += ' ';
	}
	return postfix_expression;
}
/*
ex: 3 + 4 * 2 / ( 1 - 5 )
post: 342*15-/+

	st
	
	

	
	
	
	
	
	
	
*/
int main()
{
	string a;
	getline(cin, a);
	cout<<infix_to_postfix(a);
	return 0;
}
