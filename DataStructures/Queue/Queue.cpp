#include <iostream>
#include "../Queue/Node.cpp"

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