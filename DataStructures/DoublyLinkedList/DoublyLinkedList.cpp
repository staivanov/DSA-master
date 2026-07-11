#include "../DoublyLinkedList/Node.cpp"

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
            }






};