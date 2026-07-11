#include <iostream>
#include "DoublyLinkedList.cpp"

using std::cout;
using std::endl;
using std::string;

int main(){

   DoublyLinkedList* dll = new DoublyLinkedList(10);
   dll->set(2,30);
   dll->append(50);
   dll->deleteNode(1);
   dll->printList();
   string separator(15, '*');
   cout << separator << endl;
   dll->deleteNode(3); 
   dll->printList();
   

   return 0;
}