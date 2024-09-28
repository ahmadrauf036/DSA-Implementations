#include <iostream>
#include <stack>
using namespace std;
class QueueWithStack
{
	stack<int> s1, s2;
public:
	void enqueue(int data)
	{
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		s1.push(data);
	}
	void dequeue()
	{
		try {
			if (isEmpty())
			{
				throw 1;
			}
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			s2.pop();
			
			/*
			s1		s2
					1
					2
					3
		
			
			*/

		}
		catch (int e)
		{
			cout << "Queue is empty" << endl;
		}
		
	}
	int top()
	{
		try {
			if (isEmpty())
			{
				throw 1;
			}
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			return s2.top();
		}
		catch (int e)
		{
			cout << "Queue is empty" << endl;
		}
		
		
	}
	bool isEmpty()
	{
		return (s1.empty()&& s2.empty());
	}

};



int main()
{
	QueueWithStack a;
	for (int i = 0; i < 3; i++)
	{
		a.enqueue(i + 1);
	}
	for (int i = 0; i < 4; i++)
	{
		cout << a.top() << endl; a.dequeue();
	}
}
