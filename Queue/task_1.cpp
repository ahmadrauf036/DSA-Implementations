#include <iostream>
#include "MyQueue.h"
using namespace std;
template <typename T>
MyQueue<T> AvgReplacement(MyQueue<T>& q)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += q.dequeue();
	}
	int avg;
	avg = sum / 3;
	bool chk = 0;
	MyQueue<T> q1;
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
	if(chk)
	{
		for (int i = 0; !q.isEmpty(); i++)
		{
			q1.enqueue(q.dequeue());
	
		}
		return q1;
	}
	cout<<"No Element larger than average"<<endl;
}

int main()
{
	MyQueue<int> q1;
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
