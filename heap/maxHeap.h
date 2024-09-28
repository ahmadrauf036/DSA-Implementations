#include "heap.cpp"

class maxHeap:public heap
{

public:
    void Insert(int key);
	void heapifyDown(int index);
    // void display();
    int removeMax();
};

