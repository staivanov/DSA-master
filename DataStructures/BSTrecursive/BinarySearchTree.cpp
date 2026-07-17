#include <iostream>
#include "../BinarySearchTree/Node.cpp"


class BinarySearchTree {
    public:
        Node* root;

    public:
        BinarySearchTree(){
            root = nullptr;
    }


    Node* insert(Node* currentNode, int value){
        if(currentNode == nullptr) return new Node(value);

        if(value < currentNode->value){
            currentNode->left = insert(currentNode->left, value);
        } else if( value > currentNode->value) {
            currentNode->right = insert(currentNode->right, value);
        }

        return currentNode;
    }

    void insert(int value){
        if(root == nullptr){
            root = new Node(value);
        }

        insert(root, value);
    }


    bool contains(Node* currentNode, int value){

        bool nodeExist = true,
         nonExistingNode = currentNode == nullptr;

        if (nonExistingNode)
            return !nodeExist;

        if(currentNode->value == value) return nodeExist;

        if(value < currentNode->value){
            return contains(currentNode->left, value);
        } else {
            return contains(currentNode->right, value);
        }
    }


    bool contains(int value){
        return contains(root, value);
    }
};