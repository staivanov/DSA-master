#include <iostream>
#include "../DoublyLinkedList/Node.cpp"
using namespace std;

// Functions for CRUD operations.
void append(int value);
void prepend(int value);
Node* get(int index);
bool set(int index, int value);
bool insert(int index, int value);
void deleteFirst(void);
void deleteLast(void);



//Functions for v/a checks.
bool isDLLEmpty(void);
bool isIndexNotValid(int index);
bool isDLLContainsOnlyOneElement(void);


// V/a printing functions on the LL.
void printList(void);
void getHead(void);
void getTail(void);
void getHead(void);
void getLength(void);


class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value)
        {
            Node *newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }


    void append(int value){
            Node* newNode = new Node(value);

            if(isDLLEmpty()){
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

            length++;
        }

    void prepend(int value){
            Node* newNode = new Node(value);

            if(isDLLEmpty()){
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = newNode;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

    Node* get(int index){
        if(isDLLEmpty()) return nullptr;

        Node* temp = head;
        int start,
            end = index,
            firstHalfDLL = length / 2;

        if(start < firstHalfDLL){
            for (start = 0; start < end; start++)
            {
                temp = temp->next;
            }
        }
        else {
            temp = tail;

            for(start = length - 1; start > end; start--)
                {
                    temp = temp->prev;
                }
        }
         
        return temp;
    }

    bool set(int index, int value){
        Node* temp = get(index);
        bool setSuccessefully = true;

        if(temp){
            temp->value = value;
            return setSuccessefully;
        }
        else {

        }

        return !setSuccessefully;
    }

    bool insert(int index, int value){

        bool insertSucceed = true;

        if(isIndexNotValid(index)) return !insertSucceed;

        if(isDLLEmpty()){
            prepend(value);
            return insertSucceed;
        }

        if(index == length){
            append(value);
            return insertSucceed;
        }

        Node* newNode = new Node(value);
        Node* before = get(index - 1);
        Node* after = before->next;
        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;
        length++;

        return insertSucceed;
    }


    void deleteLast(){
            Node* temp = tail;

            if(isDLLEmpty())return;
            
            if(isDLLContainsOnlyOneElement()) {
                head = nullptr;
                tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
            }

            delete temp;
            length--;
        }

    void deleteFirst() {
        if(isDLLEmpty()) return;

        Node* temp = head;
        
        if(isDLLContainsOnlyOneElement()){
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        length--;
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
     bool isDLLEmpty()
        {
            return length == 0;
        }

    private: 
        bool isDLLContainsOnlyOneElement(void){
            return length == 1;
        }

    private:
        bool isIndexNotValid(int index){
            return (index < 0) || (index >= length);
        }

};