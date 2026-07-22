#include <iostream>
#include "../BFS/binary_search_tree.cpp"

using namespace std;

int main(){

   BinarySearchTree* bst = new BinarySearchTree();
   cout << bst->root << endl;
    bst->insert(50);
    bst->insert(21);
    bst->insert(62);
    bst->BFS();
   

   return 0;
}