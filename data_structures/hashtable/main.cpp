#include <iostream>
#include "../hashtable/hashtable.cpp"
using namespace std;

int main(){

    HashTable* ht = new HashTable();
    ht->set("Varna", 9000);
    ht->set("Plovdiv", 4000);
    ht->set("Sofia", 1000);
    //ht->printTable();
    int pkVarna = ht->get("Varna");
    //cout <<"Postal code of Varna is: " << pkVarna << endl;
    vector<string> htKeys = ht->getAllKeys();

    for(string currentKey: htKeys)
        {
            cout << currentKey << " ";
        }

    cout << endl;

    return 0;
}