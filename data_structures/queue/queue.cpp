#include <iostream>
#include <climits>
#include "../queue/node.cpp"

using namespace std;

class Queue {
    private:
        Node* first = nullptr;
        Node* last = nullptr;
        int length = 0;

    public:
        Queue(int value){
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

    void enqueue(int value){
        Node* newNode = new Node(value);

        if(isQueueEmpty()){
            first = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }

        length++;
    }
    
    int dequeue(){

        if(isQueueEmpty()) return INT_MIN;

        Node* temp = first;
        int dequeueValue = first->value;
        bool isQueueContainsOnlyOneElement = length == 1;

        if(isQueueContainsOnlyOneElement){
            first = nullptr;
            last = nullptr;
        }
        else {
            first = first->next;    
        }

        delete temp;
        length--;

        return dequeueValue;
    }

    void printQueue(){
        Node* temp = first;

        while(temp){
            cout << temp->value << endl;
            temp = temp->next; 
        }
    }

    void getFirst(){
        cout << first->value << endl;
    }

    void getLast(){
        cout << last->value << endl;
    }


    void getLength(){
        cout << length << endl;
    }

    private:
        bool isQueueEmpty(){
            return length == 0;
        }
};