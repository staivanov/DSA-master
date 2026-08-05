#include <iostream>
#include "../bst_recursive/node.cpp"

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    Node* insert(Node* currentNode, int value) {
        if (currentNode == nullptr) return new Node(value);

        if (value < currentNode->value) {
            currentNode->left = insert(currentNode->left, value);
        } else if (value > currentNode->value) {
            currentNode->right = insert(currentNode->right, value);
        }

        return currentNode;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool contains(Node* currentNode, int value) {
        if (currentNode == nullptr) return false;
        if (currentNode->value == value) return true;

        if (value < currentNode->value) {
            return contains(currentNode->left, value);
        } else {
            return contains(currentNode->right, value);
        }
    }

    bool contains(int value) {
        return contains(root, value);
    }

    Node* deleteNode(Node* currentNode, int value) {
        if (currentNode == nullptr) return nullptr;

        if (value < currentNode->value) {
            currentNode->left = deleteNode(currentNode->left, value);
        } else if (value > currentNode->value) {
            currentNode->right = deleteNode(currentNode->right, value);
        } else { // Found node to delete
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                delete currentNode;
                return nullptr;
            } else if (currentNode->left == nullptr) {
                Node* temp = currentNode->right;
                delete currentNode;
                return temp;
            } else if (currentNode->right == nullptr) {
                Node* temp = currentNode->left;
                delete currentNode;
                return temp;
            } else {
                int subTreeMin = minValue(currentNode->right);
                currentNode->value = subTreeMin;
                currentNode->right = deleteNode(currentNode->right, subTreeMin);
            }
        }

        return currentNode;
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    int minValue(Node* currentNode) {
        if (currentNode == nullptr) return -1;
        while (currentNode->left != nullptr) {
            currentNode = currentNode->left;
        }
        return currentNode->value;
    }
};
