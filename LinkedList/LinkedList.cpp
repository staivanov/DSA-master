#include "../LinkedList/Node.cpp"
#include <iostream>

using namespace std;


class LinkedList{

    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value){
          Node* newNode = new Node(value);
          head = newNode;
          tail = newNode;
          length = 1;
        }

    ~LinkedList(){
        Node* temp = head;
        
        while(head){
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void append(int value){
        Node* newNode = new Node(value);

        if(isLLEmpty){
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }

        length++;
    }




    void printList(){
        Node* temp = head;
        
        while(temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
    
    void getHead(){
        cout << "Head: " << head->value << endl;
    }

    void getTail(){
        cout << "Tail: " << tail->value << endl;
    }

    void getLength(){
        cout << "Length: " << length << endl;
    }

    private:
      bool isLLEmpty()
        {
            return length == 0;
        }
};