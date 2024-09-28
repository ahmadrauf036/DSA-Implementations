#include "heap.h"

heap::heap()
{
    capacity=100;
    heapArray=new int[capacity];
    heapSize=0;
}

void heap::display()
{
    for(int i=0;i<heapSize;i++)
    {
        cout<<heapArray[i]<<" ";
    }
    cout<<endl;
}
