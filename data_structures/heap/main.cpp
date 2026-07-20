#include <iostream>
#include "../heap/heap.cpp"

int main(){

    Heap* heap = new Heap();
    heap->insert(99);
    heap->insert(71);
    heap->insert(62);
    heap->insert(59);
    heap->insert(55);
    heap->insert(18);
    heap->insert(100);
    heap->printHeap();
    heap->remove();
    heap->printHeap();

    return 0;
}   