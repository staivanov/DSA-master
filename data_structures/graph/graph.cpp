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
        bool addVertex(const string& vertex){

            if(vertexDoesntExist(vertex)){
                adjList[vertex];

                return true;
            }

            return false;
        }

        bool addEdge(const string& vertexOne,const  string& vertexTwo){

            bool bothVerticesExist = vertexExist(vertexOne) && vertexExist(vertexTwo);

            if (bothVerticesExist)
            {   // insert() returns  A pair consisting of an iterator to the inserted element and a bool value set to true if and only if the insertion took place.
                auto res1 = adjList.at(vertexOne).insert(vertexTwo);
                adjList.at(vertexTwo).insert(vertexOne);

                return res1.second;
            }

            return false;
        }

        bool removeVertex(const string& vertex){

            if(vertexDoesntExist(vertex)){
                return false;
            }

            for(const string& neighbor: adjList.at(vertex)){
                adjList.at(neighbor).erase(vertex);
            }

            adjList.erase(vertex);

            return true;
        }

        bool removeEdge(const string& vertexOne, const string& vertexTwo){

            if(vertexExist(vertexOne) && vertexExist(vertexTwo)){
                // erase() return the count of removed elements. (0 if it wasn't there and 1 for removed)
               unsigned removedCnt = adjList.at(vertexOne).erase(vertexTwo);
               adjList.at(vertexTwo).erase(vertexOne);

               return removedCnt > 0;
            }

            return false;
        }

        void printGraph(){
              
                for(const auto [vertex, edges] : adjList){

                    cout << vertex << ": [ ";

                    for(const string& edge: edges){
                        cout << edge << " ";
                    }

                    cout << "]" << endl;
                }  
        }


    private:
        bool vertexExist(const string& vertex){
                return adjList.count(vertex) == 1;
        }

        bool vertexDoesntExist(const string& vertex){
                return adjList.count(vertex) == 0;
        }

};
