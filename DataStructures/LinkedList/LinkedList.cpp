#include "../LinkedList/Node.cpp"
#include <iostream>

using namespace std;

// Functions for CRUD operations.
void append(int);
void prepend(int);
Node* get(int index);
bool set(int index, int value);
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
        /// @brief Constructor for Linked List.
        /// @param value This is the initial elemen when Linked List is created.
        LinkedList(int value){
          Node* newNode = new Node(value);
          head = newNode;
          tail = newNode;
          length = 1;
        }

    /// @brief Deallocate memory from the heap who has been allocated previously when ctr was invoked.
    ~LinkedList(){
        Node* temp = head;
        
        while(head){
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    /// @brief Append value at the end of the Linked List.
    /// @param value This element will be inserted at the end.
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

    /// @brief Prepend value at the beginning of the Linked List.
    /// @param value This element will be inserted at the beginning.
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

    /// @brief Get Node* based on provided index value from the Linked List.
    /// @param index. The numbered position of an element in the Linked List.
    /// @return `Node*` by the provided index. 
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

    /// @brief Set value at provided index in the Linked List.
    /// @param index The numbered position of an element in the Linked List.
    /// @param value This is the new element for exchange with the old element.
    /// @return `true` or `false` value.
    bool set(int index, int value){
        Node* temp = get(index);
        bool setSuccessful = true;

        if(temp){
            temp->value = value;

            return setSuccessful;
        }

        return !setSuccessful;
    }

    /// @brief Delete node at index position in the Linked List.
    /// @param index The numbered position of an element in the Linked List.
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

    /// @brief Delete first node in the Linked List.
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

    /// @brief Insert value at prodived index in the Linked List.
    /// @param index The numbered position of an element in the Linked List.
    /// @param value This element will be inserted at index position.
    /// @return `true` or `false` value.
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
    
    /// @brief Delete last node in the Linked List.
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
    /// @brief Reverse order in the Linked List.
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

    /// @brief Print all nodes in the Linked List. Every node is on new line.
    void printList(){
        Node* temp = head;
        
        while(temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
    /// @brief Print value of the head node in the Linked List.
    void getHead(){
        cout << "Head: " << head->value << endl;
    }
    /// @brief Print value of the tail node in the Linked List.
    void getTail(){
        cout << "Tail: " << tail->value << endl;
    }
     /// @brief Print current length of the Linked List.
    void getLength(){
        cout << "Length: " << length << endl;
    }

    private:
     /// @brief Check for emptiness of the Linked List.
     /// @return `true` or `false`
     bool isLLEmpty()
        {
            return length == 0;
        }

    private:
        /// @brief Check for invalid index based out of the Linked List position.
        /// @param index The numbered position of an element in the Linked List.
        /// @return `true` or `false`
        bool isIndexNotValid(int index){
            return (index < 0) || (index >= length);
        }
};