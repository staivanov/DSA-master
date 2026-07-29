#include <iostream>
#include <vector>
#include <string>
#include "../hashtable/node.cpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class HashTable
{

private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];

public:
    /// @brief Desctructor who prevents memory leaks.
    ~HashTable()
    {
        int index = 0;

        while (index < SIZE)
        {
            Node *temp = dataMap[index];

            while (temp)
            {
                Node *next = temp->next;
                delete temp;
                temp = next;
            }

            index++;
        }
    }

    /// @brief This fuction set a value by provided key into the Hash table.
    /// @param Key of type `string`.
    /// @param Value of type `int`.
    void set(string key, int value)
    {
        int index = hash(key);
        Node *newNode = new Node(key, value);

        if (dataMap[index] == nullptr)
        {
            dataMap[index] = newNode;
        }
        else
        {
            Node *temp = dataMap[index];

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    /// @brief Return an element by provided key from the Hash table.
    /// @param Key of type `string`
    /// @return `int`  
    int get(string key)
    {
        int index = hash(key);
        Node *temp = dataMap[index];

        while (temp != nullptr)
        {
            bool isThereKeysMatch = temp->key == key;

            if (isThereKeysMatch)
            {
                return temp->value;
            }

            temp = temp->next;
        }

        return -1;
    }

    ///@brief Get all the keys from the Hash table.
    ///@return `vector<string>` 
    vector<string> getAllKeys()
    {
        int index = 0;
        vector<string> allKeys = {};

        while (index < SIZE)
        {
            Node *temp = dataMap[index];

            while (temp != nullptr)
            {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }

            index++;
        }

        return allKeys;
    }


public:
    /// @brief Print every key-value pair in formatted style on the console.
    void printTable()
    {
        int index = 0;

        while (index < SIZE)
        {
            cout << index << ":" << endl;

            if (dataMap[index])
            {
                Node *temp = dataMap[index];

                while (temp)
                {
                    cout << "   {" << temp->key << " - " << temp->value << "}\n";
                    temp = temp->next;
                }
            }

            index++;
        }
    }

private:
    /// @brief A hash table uses a hash function to compute an index, also called a hash code, into a vector of buckets or slots, from which the desired value can be found.
    /// @param Key value of type `string`
    /// @return `int`
    int hash(string key)
    {
        int hashValue = 0,
            index = 0,
            keyLength = key.length();

        while (index < keyLength)
        {
            int asciiValue = int(key[index]);
            hashValue = (hashValue + asciiValue * 23) % SIZE;
            index++;
        }

        return hashValue;
    }
};