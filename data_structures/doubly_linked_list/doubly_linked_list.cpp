#include <iostream>

#include "../doubly_linked_list/node.cpp"

using namespace std;

// Functions for CRUD operations.
void append(int value);
void prepend(int value);
Node* get(int index);
bool set(int index, int value);
bool insert(int index, int value);
void deleteFirst(void);
void deleteLast(void);
void deleteNode(int index);

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
        /// @brief Constructor for Dobly Linked List.
        /// @param value This is the initial elemen when Doubly Linked List is created.
        DoublyLinkedList(int value)
        {
            Node *newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

    /// @brief Append value at the end of the Doubly Linked List.
    /// @param value This element will be inserted at the end.
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
    /// @brief Prepend value at the beginning of the Doubly Linked List.
    /// @param value This element will be inserted at the beginning.
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
    /// @brief Get Node* based on provided index value from the Doubly Linked List.
    /// @param index. The numbered position of an element in the Doubly Linked List.
    /// @return Node* by the provided index. 
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

    /// @brief Set value at provided index in the Doubly Linked List.
    /// @param index The numbered position of an element in the Doubly Linked List.
    /// @param value This is the new element for exchange with the old element.
    /// @return `true` or `false` value.
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

    /// @brief Insert value at prodived index in the Doubly Linked List.
    /// @param index The numbered position of an element in the Doubly Linked List.
    /// @param value This element will be inserted at index position.
    /// @return `true` or `false` value.
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

    /// @brief Delete first node in the Doubly Linked List.
    void deleteFirst() {
            if (isDLLEmpty())
                return;

            Node *temp = head;

            if (isDLLContainsOnlyOneElement())
            {
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

    /// @brief Delete last node in the Doubly Linked List.
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

    /// @brief Delete node at index position in the Doubly Linked List.
    /// @param index The numbered position of an element in the Doubly Linked List.
    void deleteNode(int index){

        if(isIndexNotValid(index)) return;
        if(isDLLEmpty()) return deleteFirst();
        int lastNode = length - 1;
        if(index == lastNode) return deleteLast();
   
        Node* temp = get(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
    }
    
    /// @brief Print all nodes in the Doubly Linked List. Every node is on new line.
    void printList(){
        Node* temp = head;
        
        while(temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
    /// @brief Print value of the head node in the Doubly Linked List.
    void getHead(){
        cout << "Head: " << head->value << endl;
    }
    /// @brief Print value of the tail node in the Doubly Linked List.
    void getTail(){
        cout << "Tail: " << tail->value << endl;
    }
    /// @brief Print current length of the Doubly Linked List.
    void getLength(){
        cout << "Length: " << length << endl;
    }
    
    private:
     /// @brief Check for emptiness of the Doubly Linked List.
     /// @return `true` or `false`
     bool isDLLEmpty()
        {
            return length == 0;
        }

    private: 
        /// @brief Check is there only one element in the Doubly Linked List.
        /// @param void
        /// @return `true` or `false`
        bool isDLLContainsOnlyOneElement(void){
            return length == 1;
        }

    private:
        /// @brief Check for invalid index based out of the Doubly Linked List position.
        /// @param index The numbered position of an element in the Doubly Linked List.
        /// @return `true` or `false`
        bool isIndexNotValid(int index){
            return (index < 0) || (index >= length);
        }
};