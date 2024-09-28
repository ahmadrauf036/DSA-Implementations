
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

string infix_to_prefix(string expression)
{
	Stack<char> st;
	string prefix_expression = expression;
	for (int i = 0; i < expression.length(); i++)
	{
		prefix_expression[i] = ' ';
	}
	int expI = expression.length()-1;
	bool spaceChk = 0;
	for (int i = expI; i>= 0; i--)
	{
		if (expression[i] == ' ' || (expression[i] >= '0' && expression[i] <= '9'))
		{
			if (expression[i] == ' ')
			{
				spaceChk = 1;
				continue;
			}
			prefix_expression[expI--] = expression[i];
			if (expI != 0 && spaceChk)
				prefix_expression[expI--] = ' ';
		}
		else if (expression[i] == ')')
		{
			st.Push(expression[i]);
		}
		else if (expression[i] == '(')
		{
			while (st.top() != ')')
			{
				if (st.empty())
				{
					cout << "Invalid Expression." << endl;
					return "0";
				}
				prefix_expression[expI--] = st.Pop();
				if (expI != 0 && spaceChk)
					prefix_expression[expI--] = ' ';
			}
			st.Pop();
		}
		else if (expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-' || expression[i] == '^')
		{
			while (!st.empty())
			{
				if (pres(expression[i]) <= pres(st.top()))
				{
					prefix_expression[expI--] = st.Pop();
					if (expI != 0 && spaceChk)
						prefix_expression[expI--] = ' ';
				}
				else
					break;
			}
			st.Push(expression[i]);
		}

	}
	while (!st.empty())
	{
		prefix_expression[expI--] = st.Pop();
		if (expI != -1 && spaceChk)
			prefix_expression[expI--] = ' ';
	}
	return prefix_expression;
}
int main()
{
	string a;
	getline(cin, a);
	cout << infix_to_prefix(a);
	return 0;
}
