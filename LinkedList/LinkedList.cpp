#include "../LinkedList/Node.cpp"
#include <iostream>

using namespace std;

// Functions for CRUD operations.
void append(int);
void prepend(int);
bool set(int index, int value);
Node* get(int index);
bool insert(int index, int value);
void deleteFirst(void);
void deleteLast(void);
void deleteNode(int index);

//Sorting
void reverse(void);


//Functions for v/a checks.
bool isLLEmpty(void);
bool isIndexNotValid(int index);

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
      
        if(isIndexNotValid(index)){
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

    void deleteNode(int index){

        if(isIndexNotValid(index)) return;
        if(isLLEmpty()) return deleteFirst();
        if(index == length -1) return deleteLast();

        Node* prev = get(index - 1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
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


    bool insert(int index, int value){
        bool insertSuccessful = true;

        if(isIndexNotValid(index)){
            return !insertSuccessful;
        }

        if(isLLEmpty()){
            prepend(value);
            return insertSuccessful;
        }

        if(index == length)
        {
            append(value);
            return insertSuccessful;
        }

        Node* newNode = new Node(value);
        Node* temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;

        return insertSuccessful;
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

    void reverse(){
        Node* temp = head;
        head = tail;
        tail = temp;

        Node* after = temp->next;
        Node* before = nullptr;

        for(int i = 0; i < length; i++){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
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

    private:
        bool isIndexNotValid(int index){
            return (index < 0) || (index >= length);
        }
};