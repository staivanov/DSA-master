#include <iostream>
#include "../binary_search_tree/node.cpp"

class BinarySearchTree {
    public:
        Node* root;
 
    public:
        /// @brief Default constructor for Binary Search Tree.
        BinarySearchTree() {
            root = nullptr;
        }
        // Prevent shallow copies: BST owns raw pointers, so a default
        // copy would let two trees think they own the same nodes.
        BinarySearchTree(const BinarySearchTree&) = delete;
        BinarySearchTree& operator=(const BinarySearchTree&) = delete;
          /// @brief Destructor that deallocate memory that was previlusly allocated.
        ~BinarySearchTree() {
            destroy(root);
        }
        /// @brief Insert a value at an appropriate position in the Binary Search Tree.
        /// @param value This is the value that will be inserted.
        /// @return `true` or `false` representing the result from operation
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
        /// @brief Determines if the provided value is in the Binary Search Tree.
        /// @param value This is the value that will be searched for.
        /// @return `true` or `false` representing the result from operation
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
        /// @brief Recursively deallocate all nodes in the Binary Search Tree.
        /// @param node 
        void destroy(Node* node) {
            if (node == nullptr) return;
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
};
