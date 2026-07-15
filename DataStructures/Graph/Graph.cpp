#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using std::unordered_map;
using std::unordered_set;
using std::string;
using std::endl;
using std::cout;


class Graph {
    private:
        unordered_map<string, unordered_set<string>> adjList;
    
    public:
        bool addVertex(string vertex){

            bool vertexSuccessfullyAdded = true;

            if(vertexDoesntExist(vertex)){

                adjList[vertex];

                return vertexSuccessfullyAdded;
            }

            return !vertexSuccessfullyAdded;
        }

        bool addEdge(string vertexOne, string vertexTwo){

            bool edgeSuccessfullyAdded = true;

            if (vertexExist(vertexOne) && vertexExist(vertexTwo))
            {
                adjList.at(vertexOne).insert(vertexTwo);
                adjList.at(vertexTwo).insert(vertexOne);

                return edgeSuccessfullyAdded;
            }

            return !edgeSuccessfullyAdded;
        }

        void printGraph(){
              
                for(auto [vertex, edges]: adjList){

                    cout << vertex << ": [";

                    for(string edge: edges){
                        cout << edge << " ";
                    }

                    cout << "]" << endl;
                }  
        }


    private:
        bool vertexExist(string vertex){
                return adjList.count(vertex) == 1;
        }

        bool vertexDoesntExist(string vertex){
                return adjList.count(vertex) == 0;
        }

};