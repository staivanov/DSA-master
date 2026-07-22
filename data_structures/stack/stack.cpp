#include <iostream>
#include <climits>
#include "../stack/node.cpp"
using namespace std;

class Stack{
    
    private:
        Node* top = nullptr;
        int height = 0;
        
    public:
        /// @brief Default constructor. Creates an empty stack.
        Stack(): top(nullptr), height(0) { }

        /// @brief Constructor with initial value of type int.
        /// @param value 
        Stack(int value){
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }
        /// @brief Destructor who prevents memory leaks.
        ~Stack(){
            Node* temp = top;

            while(temp != nullptr){
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
        }
    /// @brief Push value at the top of the Stack.
    /// @param `value` of type int
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
    /// @brief Remove and return the last element of the Stack.
    /// @return Return an int value.
    int pop(){

        if(isStackEmpty()) return INT_MIN;

        Node* temp = top;
        int poppedValue = top->value;
        top = top->next;
        delete temp;
        height--;

        return poppedValue;
    }
    /// @brief Print sequentially all elements of the Stack.
    void printStack(){
        Node* temp = top;

        while(temp){
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
    /// @brief  Print top value of the Stack.
    void getTop(){

        if(isStackEmpty()){
         cout << "Stack is empty." << endl;
        }

        cout << "Top: " << top->value << endl;
    }
    /// @brief Print height of the Stack.
    void getHeight(){
        cout << "Height " << height << endl;
    }
    /// @brief Return `true` or `false` value after determins is stack empty.
    private:
        bool isStackEmpty(){
            return height == 0;
        }
};  