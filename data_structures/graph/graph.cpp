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
            bool bothVerticesExist = vertexExist(vertexOne) && vertexExist(vertexTwo);

            if (bothVerticesExist)
            {
                adjList.at(vertexOne).insert(vertexTwo);
                adjList.at(vertexTwo).insert(vertexOne);

                return edgeSuccessfullyAdded;
            }

            return !edgeSuccessfullyAdded;
        }

        bool removeVertex(string vertex){

            bool successfullyRemovedVertex = true;
            
            if(vertexDoesntExist(vertex)){
                return !successfullyRemovedVertex;
            }

            for(string currentVertex: adjList.at(vertex)){
                adjList.at(currentVertex).erase(vertex);
            }
            adjList.erase(vertex);

            return successfullyRemovedVertex;
        }

        bool removeEdge(string vertexOne, string vertexTwo){

            bool edgeSuccessfullyRemoved = true;

            if(vertexExist(vertexOne) && vertexExist(vertexTwo)){

               adjList.at(vertexOne).erase(vertexTwo);
               adjList.at(vertexTwo).erase(vertexOne);

               return edgeSuccessfullyRemoved;
            }

            return !edgeSuccessfullyRemoved;
        }

        void printGraph(){
              
                for(auto [vertex, edges]: adjList){

                    cout << vertex << ": [ ";

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