#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main(){

   LinkedList* ll = new LinkedList(5);
   ll->append(50);
   ll->append(70);
   ll->append(100); 
   ll->printList();
   string separator (15, '*');
   cout << separator << endl;
   Node* n = ll->get(3);
   cout << n->value << endl;


    return 0;
}