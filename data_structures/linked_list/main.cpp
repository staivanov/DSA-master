#include <iostream>
#include "linked_list.cpp"

using namespace std;

int main(){

   LinkedList* ll = new LinkedList(10);

   ll->append(50);
   ll->append(70);
   ll->append(100); 
   
   cout << "These are elements from Linked List ll in natural order." << endl;
   ll->printList();
   string separator (15, '*');
   cout << "These are elements from Linked List ll in reverse order." << endl;
   ll->reverse();
   ll->printList();

   cout << separator << endl;

   // Demo for copy constructor.
   LinkedList *ll2 = ll;
   cout << "These are elements from Linked List ll2." << endl;
   ll2->printList();
   cout << separator << endl;

   //Demo with modification.
   ll->append(9);
   cout << "These are elements from Linked List ll after one more element is appended." << endl;
   ll->printList();
   cout << "These are elements from Linked List ll2 after one more element is appended in Linked List ll." << endl;
   ll2->printList();

   return 0;
}