
#include "minHeap.cpp"

int main()
{
    minHeap h;
    h.Insert(6);
    h.Insert(5);
    h.Insert(4);
    h.Insert(3);
    h.Insert(2);
    h.Insert(1);
    h.display();
    cout<<h.removeMin()<<endl;
    h.display();
    
}