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
        /// @brief Create an empty Queue.
        Queue() = default;

        /// @brief Create a Queue with initial value of `int` type.
        /// @param `int` type
        Queue(int value)
        {
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

        /// @brief Deep Copy copy constructor. 
        /// @param `const Queue by reference` 
        Queue(const Queue& other){
            copyFrom(other);
        }
        // Deep Copy Assignment operator
        Queue& operator=(const Queue& other){
            // Self-assignment check
            if(this == &other){
                return *this;
            }
            // Free existing memory before copying.
            clear();
            // Copy elements from source queue.
            copyFrom(other);

            return *this;
        }

        /// @brief Destructor who prevents memory leaks.
        ~Queue(){
            clear();
        }
        /// @brief Clear all dynamically allocated nodes.
        void clear()
        {

            while(!isQueueEmpty()){
                dequeue();
            }
        }

    /// @brief Add value at the rear (back) end.
    /// @param `int` type 
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
    
    /// @brief Return and remove value from the front of a Queue.
    /// @return `int` type
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

    /// @brief Print every item from the Queue in sequential order.
    void printQueue(){
        Node* temp = first;

        while(temp){
            cout << temp->value << " ";
            temp = temp->next; 
        }

        cout << endl;
    }
    /// @brief Print element from the front of a Queue.
    void getFirst(){
        if(isQueueEmpty()) return;
        cout << first->value << endl;
    }
    /// @brief Print element from the rear (back) of a Queue.
    void getLast(){
        if(isQueueEmpty()) return;
        cout << last->value << endl;
    }

    /// @brief Get actual length on the Queue.
    void getLength(){
        cout << length << endl;
    }
    
    private:
        /// @brief Determines is Queue empty or not.
        /// @return `true` or `false`
        bool isQueueEmpty(){
            return length == 0;
        }
        /// @brief Helper method that clone nodes from another queue.
        /// @param `const Queue by reference` 
        void copyFrom(const Queue& other){
            Node *current = other.first;

            while(current != nullptr){
                enqueue(current->value);
                current = current->next;
            }
        }
};