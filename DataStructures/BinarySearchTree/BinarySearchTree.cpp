#include <iostream>
#include "../BinarySearchTree/Node.cpp"


class BinarySearchTree {
    public:
        Node* root;

    public:
        BinarySearchTree(){
            root = nullptr;
    }

    bool insert(int value){
        Node* newNode = new Node(value);

        if(root = nullptr){
            root = newNode;
            return true;
        }

        Node* temp = root; 
        bool areNodesDifferent = true,
             nodeSuccessfullyPlaced = true;
        
        while(true){
            if(newNode->value == temp->value) 
                return false;

            if(newNode->value < temp->value)
            {
                bool isLeftSideEmpty = temp->left == nullptr;

                if(isLeftSideEmpty){
                    temp->left = newNode;

                    return true;
                }

                temp = temp->left;
            } else {
                bool  isRightSideEmpty = temp->right == nullptr;

                if(isRightSideEmpty){
                    temp->right = newNode;

                    return true;
                }

                temp = temp->right;
            }
        }
    }

    bool contains(int value){
        
        bool nodeExist = true;
        Node* temp = root;

        while(temp){
            if(value < temp->value){
                temp = temp->left;
            } else if(value > temp->value) {
                temp = temp->right;
            }
            else {
                return nodeExist;
            }
        }

        return !nodeExist;
    }

};