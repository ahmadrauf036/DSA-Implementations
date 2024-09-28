#include "maxHeap.h"

void maxHeap::Insert(int key)
{
    if(heapSize==0)
    {
        heapArray[heapSize]=key;
        heapSize++;
    }
    else
    {
        heapArray[heapSize]=key;
        heapifyDown(heapSize);
        heapSize++;
    }
    
}

void maxHeap::heapifyDown(int index)
{
    if(index==0)
        return;
    if(heapArray[(index-1)/2]<heapArray[index])
    {
        swap(heapArray[(index-1)/2],heapArray[index]);
        heapifyDown((index-1)/2);
    }
}


int maxHeap::removeMax()
{
    if(heapSize==0)
    {
        return int();
    }
    int max=heapArray[0];
    heapArray[0]=heapArray[heapSize-1];
    heapSize--;
    int index=heapSize;
    while (index!=0)
        heapifyDown(index--);
    return max;
}
