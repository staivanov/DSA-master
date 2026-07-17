#include <iostream>
#include "../BinarySearchTree/Node.cpp"


class BinarySearchTree {
    public:
        Node* root;

        
    public:
        BinarySearchTree(){
            root = nullptr;
        }

    public:
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

        //Delete a leaf Node, Node with left or right child and two children.
        Node* deleteNode(Node* currentNode, int value){

            if(value < currentNode->value){
                currentNode->left = deleteNode(currentNode->left, value);
            } else { 
                if(currentNode->left == nullptr && currentNode->right == nullptr){
                    delete(currentNode);

                    return nullptr;
                } else if(currentNode->left == nullptr){

                    Node* temp = currentNode->right;
                    delete(currentNode);

                    return temp;
                } else if(currentNode->right == nullptr){

                    Node *temp = currentNode->left;
                    delete(currentNode);

                    return temp;
                } else {

                     int subTreeMin = minValue(currentNode->right);
                     currentNode->value = subTreeMin;
                     currentNode->right = deleteNode(currentNode->right, subTreeMin); 
                }
            }

            return currentNode;
        }


        void deleteNode(int value)
        {
            root = deleteNode(root, value);
        }


        int minValue(Node* currentNode){

            while(currentNode->left != nullptr){
                currentNode = currentNode->left;
            }

            return currentNode->value;
        }
};