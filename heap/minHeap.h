#include "heap.cpp"
class minHeap:public heap
{

public:
    void Insert(int key);
	void heapifyUp(int index);
    int removeMin();
};




