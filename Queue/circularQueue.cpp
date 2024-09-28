#include <iostream>
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
int main()
{
	CircularQueue<int> cQ;
	for (int i = 0; i < 10; i++)
	{
		cQ.enqueue(i + 1);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << cQ.peek() << " ";
		cQ.dequeue();
	}
	for (int i = 0; i < 10; i++)
	{
		cQ.enqueue(i + 10);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << cQ.peek() << endl;
		cQ.dequeue();
	}
}
