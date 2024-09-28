#include <iostream>
using namespace std;
template <typename T>
class Queue
{
protected:
	int front;
	int rear;
	int maxSize;
	T* arr;


public:
	virtual bool isFull()= 0;
	virtual bool isEmpty() = 0;
	virtual void display() = 0;
	virtual void enqueue(T data) = 0;
	virtual T dequeue() = 0;
	virtual T size() = 0;
	virtual T peek() = 0;
	Queue();
};
template <typename T>
Queue<T>::Queue()
{
	maxSize = 1000;
	rear = -1;
	front = -1;
	arr = new int[maxSize];
}
