#include <iostream>
#include <stack>
using namespace std;

template <class T>
stack<T> removeDuplicate(stack<T> &st1)
{
	T ver;
	stack<T> st2, temp;
	while(!st1.empty())
	{
		bool found = 0;
		ver = st1.top();
		st1.pop();
		while (!st1.empty())
		{
			if (st1.top() == ver)
			{
				found = 1;
			}
			temp.push(st1.top());
			st1.pop();
		}
		if (!found)
		{
			st2.push(ver);
		}
		while (!temp.empty())
		{
			st1.push(temp.top());
			temp.pop();
		}
		
	}
	
	return st2;
}

int main()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(1);
	st.push(4);
	st.push(5);
	
	stack<int> stWithoutDuplicates = removeDuplicate(st);
	cout << stWithoutDuplicates.top() << endl; stWithoutDuplicates.pop();
	cout << stWithoutDuplicates.top() << endl; stWithoutDuplicates.pop();
	cout << stWithoutDuplicates.top() <<endl; stWithoutDuplicates.pop();
	cout << stWithoutDuplicates.top() << endl; stWithoutDuplicates.pop();
}