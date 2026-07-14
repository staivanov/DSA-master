#include <iostream>
#include "../HashTable/Node.cpp"

using std::cout;
using std::endl;

class HashTable {

    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];
        
    
    public:
        void set(string key, int value){
            int index = hash(key);
            Node* newNode = new Node(key, value);

            if(dataMap[index] == nullptr) {
                
                dataMap[index] = newNode;
            } else {
                Node* temp = dataMap[index];

                while(temp->next != nullptr){
                    temp = temp->next;
                }

                temp->next = newNode;
            }
        }

    public:
        void printTable(){
            int index = 0;

            while(index < SIZE){
                cout << index << ":" << endl;
                if(dataMap[index]){
                    Node* temp = dataMap[index];
                    while(temp){
                        cout << "   {" << temp->key << " - " << temp->value << "}\n";
                        temp = temp->next;
                    }
                }
                index++;
            }
        }

    private:
        int hash(string key)
        {
            int hash = 0;
            int index = 0,
                   keyLength = key.length();

            while (index < keyLength)
            {
                int asciiValue = int(key[index]);
                hash = (hash + asciiValue * 23) % SIZE;
                index++;
            }

            return hash;
        }
};