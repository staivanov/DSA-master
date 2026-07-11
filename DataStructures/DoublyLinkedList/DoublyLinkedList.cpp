#include "../DoublyLinkedList/Node.cpp"

// Functions for CRUD operations.
void append(int value);

//Functions for v/a checks.
bool isDLLEmpty(void);
bool isIndexNotValid(int index);


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
        bool isIndexNotValid(int index){
            return (index < 0) || (index >= length);
        }

};