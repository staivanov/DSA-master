#include <iostream>
using std::string;

class Node {
    public:
        string key;
        int value;
        Node* next;

    Node(string key, int value){
        this->key = key;
        this->value = value;
    }
};