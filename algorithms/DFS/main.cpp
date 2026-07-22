#include <iostream>
#include "../DFS/binary_search_tree.cpp"


using namespace std;

int main(){

   BinarySearchTree* bst = new BinarySearchTree();

   cout << bst->root << endl;

    bst->insert(45);
    bst->insert(21);
    bst->insert(76);   
    bst->insert(15);
    bst->insert(26);
    bst->insert(55);
    bst->insert(88);


    bst->DFSPreOrder();
    cout << flush << "\n";
    
   return 0;
};

