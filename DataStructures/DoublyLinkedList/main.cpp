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
   cout <<"Value at index 0 before set() function is: " << dll->get(0)->value << endl;
   string separator(15, '*');
   cout << separator << endl;
   dll->set(0, 5);
   cout <<"Value at index 0 after set() function is: " << dll->get(0)->value << endl;
   

   return 0;
}