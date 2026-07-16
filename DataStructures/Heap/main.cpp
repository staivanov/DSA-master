#include <iostream>
#include "../Heap/Heap.cpp"

int main(){

    Heap* heap = new Heap();
    heap->insert(99);
    heap->insert(71);
    heap->insert(62);
    heap->insert(59);

    heap->printHeap();

    heap->insert(150);
    heap->printHeap();

    heap->insert(75);
    heap->printHeap();



    return 0;
}