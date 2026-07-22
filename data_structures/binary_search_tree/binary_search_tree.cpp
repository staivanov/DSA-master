#include <iostream>
#include "../binary_search_tree/node.cpp"


class BinarySearchTree {
    public:
        Node* root;

    public:
        BinarySearchTree(){
            root = nullptr;
    }

    bool insert(int value){

        Node* newNode = new Node(value);
        bool areNodesDifferent = true,
             nodeSuccessfullyPlaced = true;

        if(root == nullptr){
            root = newNode;
            return nodeSuccessfullyPlaced;
        }

        Node* temp = root;

        while(true){ 

            if(newNode->value == temp->value) 
                return !nodeSuccessfullyPlaced;

            if(newNode->value < temp->value)
            {
                bool isLeftSideEmpty = temp->left == nullptr;

                if(isLeftSideEmpty){
                    temp->left = newNode;

                    nodeSuccessfullyPlaced = true;
                    return nodeSuccessfullyPlaced;
                }

                temp = temp->left;
            } else {
                
                bool isRightSideEmpty = (temp->right == nullptr);

                if(isRightSideEmpty){
                    temp->right = newNode;

                        nodeSuccessfullyPlaced = true;
                    return nodeSuccessfullyPlaced;
                }

                temp = temp->right;
            }
        }
    }

    bool contains(int value){
        
        bool nodeExist = true;

        if (root == nullptr)
            return !nodeExist;

        Node* temp = root;

        while (temp != nullptr)
        {
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