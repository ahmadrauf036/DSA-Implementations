#pragma once

#include <iostream>
using namespace std;

class heap
{
protected:
	int *heapArray; 
	int capacity; 
	int heapSize;
    
    heap();
   	virtual void Insert(int key)=0;
public:
    void display();
};
