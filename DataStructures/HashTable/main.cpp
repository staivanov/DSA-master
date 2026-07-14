#include <iostream>
#include "../HashTable/HashTable.cpp"
using namespace std;

int main(){

    HashTable* ht = new HashTable();
    ht->set("Varna", 9000);
    ht->set("Plovdiv", 4000);
    ht->set("Sofia", 1000);
    ht->printTable();



    return 0;
}