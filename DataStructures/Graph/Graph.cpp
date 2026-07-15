#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using std::unordered_map;
using std::unordered_set;
using std::string;



class Graph {
    private:
        unordered_map<string, unordered_set<string>> adjList;

    bool addVertex(string vertex){

        bool vertexSuccessfullyAdded = true;

        if(elementDoesntExist(vertex)){
            adjList[vertex];

            return vertexSuccessfullyAdded;
        }
        
        return !vertexSuccessfullyAdded;
    }


    private:
        bool elementExist(string vertex){
                adjList.count(vertex) == 1;
        }
        bool elementDoesntExist(string vertex){
                adjList.count(vertex) == 0;
        }

};