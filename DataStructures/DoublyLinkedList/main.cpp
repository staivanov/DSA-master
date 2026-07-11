#include <iostream>
#include "DoublyLinkedList.cpp"

using std::cout;
using std::endl;
using std::string;

int main(){

   DoublyLinkedList* dll = new DoublyLinkedList(10);
   dll->append(30);
   dll->append(50);
   dll->printList();
   string separator(15, '*');
   cout << separator << endl;
   dll->insert(1, 99);
   dll->printList();
   

   return 0;
}