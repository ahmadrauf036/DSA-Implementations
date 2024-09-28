#include <iostream>
#include "Queue.h"
using namespace std;
template <typename T>
class MyQueue :public Queue<T>
{
public:
	bool isFull();
	bool isEmpty();
	void display();
	void enqueue(T data);
	T dequeue();
	int size();
	T peek();
};
template <typename T>

bool MyQueue<T>::isFull()
{
	if (this->rear == 1000)
		return 1;
	return 0;
}
template <typename T>
bool MyQueue<T>::isEmpty()
{
	if (this->front == -1 && this->rear == -1)
		return 1;
	return 0;
}
template <typename T>
void MyQueue<T>::display()
{
	for (int i = this->front; i <= this->rear; i++)
	{
		cout << this->arr[i] << " ";
	}
	cout << endl;
}
template <typename T>
void MyQueue<T>::enqueue(T data)
{
	if (isFull())
	{
		cout<<"Full of Elements";
	}
	this->rear++;
	this->arr[this->rear] = data;
	if (this->front == -1)
		this->front++;
}
template <typename T>
T MyQueue<T>::dequeue()
{
	if (isEmpty())
	{
	cout<<"No Elements";
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
T MyQueue<T>::peek()
{
	if (isEmpty())
	{
		cout<<"No Elements";

	}
	T data = this->arr[this->front];
	return data;
}
template <typename T>
int MyQueue<T>::size()
{
	return (this->rear + 1);
}

