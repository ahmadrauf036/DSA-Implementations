#include <iostream>
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
	void Pop()
	{
		if (!empty())
		{
			stackTop--;
			return;
		}
		else
		{
			cout << "Stack underflow." << endl;
			return;
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
	void reverseRecursion()
	{
		if(!empty())
		{
			T a=top();
			Pop();
			reverseRecursion();
			Push(a);
		}
	}
};

template <typename T>
void peekElement(Stack<T> s1)
{
	Stack<T> s2;
	s2.Push(s1.top());
	s1.Pop();
	bool check = false;
	while (!s1.empty())
	{
		if (s1.top() > s2.top())
		{
			s2.Push(s1.top());
			s1.Pop();
			if (s1.top() < s2.top())
			{
				cout << s2.top() << " ";
				s2.Push(s1.top());
				s1.Pop();
				check = true;
			}
		}
		else
		{
			s2.Push(s1.top());
			s1.Pop();
		}
	}
	if (!check)
		cout << "No Peek Element." << endl;
	cout << endl;
}
int main()
{
	Stack<int> s1;
	int c = 0;
	while (c < 5)
	{
		s1.Push(c);
		c++;
	}
	s1.reverseRecursion();
	c = 0;
	while (c < 5)
	{
		cout<<s1.top();
		s1.Pop();
		c++;
	}
	return 0;
	// 1 2 3 5 4
	// 1 3 2 4 5
	/*
	s1		s2
			
			
	3		
	2		5
	1		4

	*/
}