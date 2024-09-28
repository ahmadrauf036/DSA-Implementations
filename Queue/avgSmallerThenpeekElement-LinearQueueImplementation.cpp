#include <iostream>
using namespace std;

template <typename T>
class Queue
{
	int front;
	int rear;
	int maxSize;
	T* arr;

public:
	bool isFull();
	bool isEmpty();
	void display();
	void enqueue(T data);
	T dequeue();
	int size();
	T peek();
	Queue();
};

template <typename T>
Queue<T> AvgReplacement(Queue<T>& q)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += q.dequeue();
	}
	int avg;
	avg = sum / 3;
	bool chk = 0;
	Queue<T> q1;
	for (int i = 0; i < q.size(); i++)
	{
		if (avg < q.peek())
		{
			q1.enqueue(avg);
			chk = 1;
			break;
		}
		q.dequeue();
	}
	/*
	q 	  1 1
	q1
	*/
	if (chk)
	{
		for (int i = 0; !q.isEmpty(); i++)
		{
			q1.enqueue(q.dequeue());

		}
		return q1;
	}
	cout << "No Element larger than average" << endl;
}

int main()
{
	Queue<int> q1;
	cout << "Enter Elements in queue.(-1 to terminate)" << endl;
	int userInput = -1;
	cin >> userInput;
	for (int i = 0; userInput != -1; i++)
	{
		q1.enqueue(userInput);
		cin >> userInput;
	}
	AvgReplacement(q1).display();

	return 0;

}



template <typename T>

bool Queue<T>::isFull()
{
	if (this->rear == 1000)
		return 1;
	return 0;
}
template <typename T>
bool Queue<T>::isEmpty()
{
	if (this->front == -1 && this->rear == -1)
		return 1;
	return 0;
}
template <typename T>
void Queue<T>::display()
{
	for (int i = this->front; i <= this->rear; i++)
	{
		cout << this->arr[i] << " ";
	}
	cout << endl;
}
template <typename T>
void Queue<T>::enqueue(T data)
{
	if (isFull())
	{
		cout << "Full of Elements";
	}
	this->rear++;
	this->arr[this->rear] = data;
	if (this->front == -1)
		this->front++;
}
template <typename T>
T Queue<T>::dequeue()
{
	if (isEmpty())
	{
		cout << "No Elements";
	}
	T data = this->arr[0];
	if (this->front == this->rear)
	{
		this->front = this->rear = -1;
		return data;
	}
	for (int i = 0; i < size(); i++)
	{
		this->arr[i] = this->arr[i + 1];
	}
	this->rear--;
	return data;
}
template <typename T>
T Queue<T>::peek()
{
	if (isEmpty())
	{
		cout << "No Elements";

	}
	T data = this->arr[this->front];
	return data;
}
template <typename T>
int Queue<T>::size()
{
	return (this->rear + 1);
}
template <typename T>
Queue<T>::Queue()
{
	maxSize = 1000;
	rear = -1;
	front = -1;
	arr = new int[maxSize];
}