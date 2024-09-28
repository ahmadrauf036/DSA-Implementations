#include<iostream>
using namespace std;
template <typename T>
class CircularQueue
{
	int front, rear;
	int maxSize = 1000;
	T* array;
public:
	CircularQueue()
	{
		array = new T[maxSize];
		front = rear = -1;
	}
	~CircularQueue()
	{
		delete[] array;
	}
	bool isempty()
	{
		if (rear == -1 && front == -1)
		{
			return true;
		}
		return false;
	}
	bool isfull()
	{
		if ((front == 0 && rear == maxSize - 1) || rear == front - 1)
			return true;
		return false;
	}
	void enqueue(T data)
	{
		try
		{
			if (isfull())
			{
				throw isfull();
			}
			if (isempty())
			{
				front++;
			}
			rear = (rear + 1) % maxSize;
			array[rear] = data;
		}
		catch (bool e)
		{
			cout << "Queue full." << endl;
		}
		
	}
	void dequeue()
	{
		try
		{

		if (isempty())
		{
			throw isempty();
		}
		if (front == rear)
		{
			front = rear = -1;
		}
		else
			front = (front + 1) % maxSize;
		}
		catch (bool e)
		{
			cout << "Queue is empty." << endl;
		}

	}
	T Front()
	{
		try
		{

			if (isempty())
			{
				throw isempty();
			}
				return array[front];
		}
		catch (bool e)
		{
			cout << "Queue is empty." << endl;
		}
	}
};
template <typename T>
class stack_using_queue
{
	CircularQueue<T> q1, q2;
	int s;
public:
	stack_using_queue()
	{
		s = 0;
	}
	void Push(T value)
	{
		q1.enqueue(value);
		while (!q2.isempty())
		{
			q1.enqueue(q2.Front());
			q2.dequeue();
		}
		CircularQueue<int> temp = q1;
		q1 = q2;
		q2 = temp;
		s++;
	}
		
	void Pop()
	{
		try
		{
			if (q2.isempty())
			{
				throw q2.isempty();
			}
			q2.dequeue();
		}
		catch (bool e)
		{
			cout << "Empty Queue." << endl;
		}
		
	}
	T Top()
	{
		try
		{
			if (q2.isempty())
			{
				throw q2.isempty();
			}
			return q2.Front();
		}
		catch (bool e)
		{
			cout << "Empty Queue." << endl;
		}

	}
};
int main()
{
	stack_using_queue<int> st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	cout << st.Top() << endl; st.Pop();
	cout << st.Top() << endl; st.Pop();
	cout << st.Top() << endl; st.Pop();
	cout << st.Top() << endl; st.Pop();
	cout << st.Top() << endl; st.Pop();
}
