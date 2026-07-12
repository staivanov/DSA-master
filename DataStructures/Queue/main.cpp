#include <iostream>
#include "../Queue/Queue.cpp"

using namespace std;

int main(){

    Queue* queue = new Queue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    queue->printQueue();




    return 0;
}