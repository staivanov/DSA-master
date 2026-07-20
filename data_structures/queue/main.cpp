#include <iostream>
#include "../queue/queue.cpp"

using namespace std;

int main(){

    Queue* queue = new Queue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    queue->printQueue();
    string tkn(15, '*');
    cout << tkn << endl;
    queue->dequeue();
    queue->printQueue();

    return 0;
}