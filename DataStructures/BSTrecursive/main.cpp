#include <iostream>
#include "../BinarySearchTree/BinarySearchTree.cpp"

using namespace std;


int main(){

   BinarySearchTree* bst = new BinarySearchTree();
   cout << bst->root << endl;
   bst->insert(40);
   bst->insert(20);
   bst->insert(76);
   bst->insert(15);
   bst->insert(52);
   bst->insert(86);

   cout << bst->root->left->right->value << endl;
   
   return 0;
} 