#include <iostream>
#include "../BFS/node.cpp"
#include <queue>

using std::queue;
using std::flush;
using std::cout;

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
            {
                delete newNode;
                
                return !nodeSuccessfullyPlaced;
            }
            if(newNode->value < temp->value)
            {
                bool isLeftSideEmpty = temp->left == nullptr;

                if(isLeftSideEmpty){
                    temp->left = newNode;
                    
                    return nodeSuccessfullyPlaced;
                }

                temp = temp->left;
            } else {
                
                bool isRightSideEmpty = (temp->right == nullptr);

                if(isRightSideEmpty){
                    temp->right = newNode;

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


    void BFS(){

        if(root == nullptr) return;

        queue<Node*> myQueue;
        myQueue.push(root);
        
        while(!myQueue.empty()){

            Node* currentNode = myQueue.front();
            myQueue.pop();
            cout << currentNode->value << " ";

            bool leftCurrentNodeExist = currentNode->left != nullptr;

            if(leftCurrentNodeExist){
                myQueue.push(currentNode->left);
            }

            bool rightCurrentNodeExist = currentNode->right != nullptr;

            if(rightCurrentNodeExist){
                myQueue.push(currentNode->right);
            }
        }

        cout << flush << "\n";
    }
};