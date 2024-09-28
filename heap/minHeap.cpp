#include "minHeap.h"

void minHeap::Insert(int key){
    if(heapSize==0)
    {
        heapArray[heapSize]=key;
        heapSize++;
    }
    else
    {
        heapArray[heapSize]=key;
        heapifyUp(heapSize);
        heapSize++;
    }
    
}
//6 5 4 3 2 1

void minHeap::heapifyUp(int index)
{
    if(index==0)
        return;
    if(heapArray[(index-1)/2]>heapArray[index])
    {
        swap(heapArray[(index-1)/2],heapArray[index]);
        heapifyUp((index-1)/2);
    }
}

int minHeap::removeMin()
{
    if(heapSize==0)
    {
        return int();
    }
    int min=heapArray[0];
    heapArray[0]=heapArray[heapSize-1];
    heapSize--;
    int index=heapSize;
    while (index!=0)
        heapifyUp(index--);
    return min;
}
//2 5 4 6 3
//
