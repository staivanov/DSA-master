class Node{
    public:
        int value;
        Node* left;
        Node* right;

    public:
        Node(int value){
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};