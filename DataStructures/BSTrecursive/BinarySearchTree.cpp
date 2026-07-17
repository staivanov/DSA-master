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
        bool areNodesDifferent = true,
             nodeSuccessfullyPlaced = true;

        if(root = nullptr){
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

    bool rContains(Node* currentNode, int value){

        


    }


    bool rContains(int value){
        return rContains(root, value);
    }

};