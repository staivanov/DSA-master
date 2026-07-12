#include <iostream>
#include <climits>
#include "../Stack/Node.cpp"
using namespace std;

class Stack{
    
    private:
        Node* top = nullptr;
        Node* bottom = nullptr;
        int height = 0;
        
    public:
        Stack(int value){
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

    void push(int value){
        Node* newNode = new Node(value);

        if(isStackEmpty()){
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }

        height++;
    }

    int pop(){

        if(isStackEmpty()) return INT_MIN;

        Node* temp = top;
        int poppedValue = top->value;
        top = top->next;
        delete temp;
        height--;

        return poppedValue;
    }

    void printStack(){
        Node* temp = top;

        while(temp){
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getTop(){
        cout << "Top: " << top->value << endl;
    }

    void getHeight(){
        cout << "Height " << height << endl;
    }

    private:
        bool isStackEmpty(){
            return height == 0;
        }


};  