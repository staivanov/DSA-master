#include <iostream>
#include "../binary_search_tree/node.cpp"

class BinarySearchTree {
    public:
        Node* root;
 
    public:
        BinarySearchTree() {
            root = nullptr;
        }
 
        BinarySearchTree(const BinarySearchTree&) = delete;
        BinarySearchTree& operator=(const BinarySearchTree&) = delete;
 
        ~BinarySearchTree() {
            destroy(root);
        }
 
        bool insert(int value) {
            if (root == nullptr) {
                root = new Node(value);
                return true;
            }
 
            Node* temp = root;
            while (true) {
                if (value == temp->value) {
                    return false; // duplicate, nothing allocated, nothing leaked
                }
 
                if (value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = new Node(value);
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = new Node(value);
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }
 
        bool contains(int value) {
            Node* temp = root;
            while (temp != nullptr) {
                if (value < temp->value) {
                    temp = temp->left;
                } else if (value > temp->value) {
                    temp = temp->right;
                } else {
                    return true;
                }
            }
            return false;
        }
 
    private:
        void destroy(Node* node) {
            if (node == nullptr) return;
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
};
