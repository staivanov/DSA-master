#include <iostream>
#include "../bst_recursive/node.cpp"

class BinarySearchTree {
public:
    /// @brief Pointer to the root node of the binary search tree.
    Node* root;
    /// @brief Constructs an empty Binary Search Tree with a null root.
    BinarySearchTree() {
        root = nullptr;
    }
    /// @brief Recursively traverses the tree to insert a new value into a given subtree.
    /// @param currentNode Pointer to the root of the current subtree being processed.
    /// @param value The integer value to insert into the subtree.
    /// @return Pointer to the root node of the modified subtree.
    Node* insert(Node* currentNode, int value) {
        if (currentNode == nullptr) return new Node(value);

        if (value < currentNode->value) {
            currentNode->left = insert(currentNode->left, value);
        } else if (value > currentNode->value) {
            currentNode->right = insert(currentNode->right, value);
        }

        return currentNode;
    }
    /// @brief Inserts a new value into its proper position within the Binary Search Tree.
    /// @param value The integer value to insert into the tree.
    void insert(int value) {
        root = insert(root, value);
    }

    /// @brief Determines if the provided value is in the Binary Search Tree.
    // @param currentNode Pointer to the root of the current subtree being searched.
    /// @param value This is the value that will be searched for.
    /// @return `true` or `false` representing the result from operation.
    bool contains(Node* currentNode, int value) {
        if (currentNode == nullptr) return false;
        if (currentNode->value == value) return true;

        if (value < currentNode->value) {
            return contains(currentNode->left, value);
        } else {
            return contains(currentNode->right, value);
        }
    }
    /// @brief Determines if the provided value is in the Binary Search Tree.
    /// @param value This is the value that will be searched for.
    /// @return `true` or `false` representing the result from operation.
    bool contains(int value) {
        return contains(root, value);
    }
    /// @brief Recursively searches and deletes a node with the specified value from a subtree.
    /// @details Handles three deletion cases: leaf nodes, nodes with one child, and nodes with two children.
    /// @param currentNode Pointer to the root of the current subtree being processed.    
    /// @param value The integer value of the node to remove.
    /// @return Pointer to the root node of the updated subtree.
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
    /// @brief Deletes a node with the provided value from the Binary Search Tree.
    /// @param value The integer value to delete.
    void deleteNode(int value) {
        root = deleteNode(root, value);
    }
    /// @brief Finds the minimum value stored in a subtree by traversing to the leftmost node.
    /// @param currentNode Pointer to the root of the subtree to search.
    /// @return The smallest integer value in the subtree, or -1 if the subtree is empty.
    int minValue(Node* currentNode) {
        if (currentNode == nullptr) return -1;
        while (currentNode->left != nullptr) {
            currentNode = currentNode->left;
        }
        return currentNode->value;
    }
};
