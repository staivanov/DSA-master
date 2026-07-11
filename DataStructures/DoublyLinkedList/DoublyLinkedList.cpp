#include "../DoublyLinkedList/Node.cpp"

// Functions for CRUD operations.
void append(int value);
void prepend(int value);
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
            DoublyLinkedList(int value){
                Node* newNode = new Node(value);
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

        void prepent(int value){
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