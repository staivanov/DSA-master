#include <iostream>
#include "../bst_recursive/binary_search_tree_rec.cpp"

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

   cout << bst->minValue(bst->root)<< endl;
   
   return 0;
} 