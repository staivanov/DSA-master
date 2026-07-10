#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main(){

   LinkedList* ll = new LinkedList(5);
   ll->append(50);
   ll->append(70);
   ll->append(100);
   ll->deleteLast();
   ll->printList();
   ll->prepend(11);



    return 0;
}