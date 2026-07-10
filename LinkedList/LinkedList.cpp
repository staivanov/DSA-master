#include "../LinkedList/Node.cpp"
#include <iostream>

using namespace std;

// Methods for manipulating over the LL.
void append(int);
void prepend(int);
Node* get(int index);

bool isLLEmpty(void);
void deleteLast(void);
void deleteFirst(void);
bool set(int index, int value);

// V/a printing functions on the LL.
void printList(void);
void getHead(void);
void getTail(void);
void getHead(void);
void getLength(void);


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

        if(isLLEmpty()){
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }

        length++;
    }

    void prepend(int value){
        Node* newNode = new Node(value);

        if(isLLEmpty()){
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    Node* get(int index){

        bool isIndexNotValid = (index < 0) || (index >= length);
        
        if(isIndexNotValid){
            return nullptr;
        }

        Node* temp = head;
        int cnt = 0;

        while(cnt < index){
            temp = temp->next;
            cnt++;
        }
        return temp;
    }

    void deleteFirst(){

        if(isLLEmpty()) return;

        Node* temp = head;

        if(length == 1){
            head = nullptr;
            tail = nullptr;
        } else {
           head = head->next;
        }

       delete temp;
       length--;
    }

    bool set(int index, int value){
        Node* temp = get(index);
        bool setSuccessful = true;

        if(temp){
            temp->value = value;

            return setSuccessful;
        }

        return !setSuccessful;
    }

    void deleteLast(){
        if (isLLEmpty())
            return;

        Node* temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *pre = head;

            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }

            tail = pre;
            tail->next = nullptr;
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
     bool isLLEmpty()
        {
            return length == 0;
        }
};