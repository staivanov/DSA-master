#include <iostream>
#include "../HashTable/Node.cpp"

using std::cout;
using std::endl;

class HashTable {

    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];
        


    public:
        void printTable(){
            int index = 0;

            while(index < SIZE){
                cout << index << ":" << endl;
                if(dataMap[index]){
                    Node* temp = dataMap[index];
                    while(temp){
                        cout << "   {" << temp->key << " - " << temp->value << "}";
                        temp = temp->next;
                    }
                }
                index++;
            }
        }
};