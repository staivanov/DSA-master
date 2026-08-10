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
        /// @brief This is a container that holds the graph with provided vertices and edges.
        unordered_map<string, unordered_set<string>> adjList;
    
    public:
        /// @brief It performs insertion at the proper place in the Graph.
        /// @param vertex of type `const string&` to be added.
        /// @return `true` or `false` based on whether the vertex was added or didn't.
        bool addVertex(const string& vertex){
            if(vertexDoesntExist(vertex)){
                adjList[vertex];
                return true;
            }

            return false;
        }
        /// @brief It adds two vertices where an edge will be formed between them.
        /// @param vertexOne 
        /// @param vertexTwo 
        /// @return `true` or `false` based on whether the edge was added or didn't.
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

        /// @brief It remove the provided vertex from the graph.
        /// @param vertex 
        /// @return `true` or `false` based on whether the vertex was removed or didn't.
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
        /// @brief It remove edge between two vertices.
        /// @param vertexOne 
        /// @param vertexTwo 
        /// @return `true` or `false` based on whether the edge was removed or didn't.
        bool removeEdge(const string& vertexOne, const string& vertexTwo){

            if(vertexExist(vertexOne) && vertexExist(vertexTwo)){
                // erase() return the count of removed elements. (0 if it wasn't there and 1 for removed)
               unsigned removedCnt = adjList.at(vertexOne).erase(vertexTwo);
               adjList.at(vertexTwo).erase(vertexOne);

               return removedCnt > 0;
            }

            return false;
        }
        /// @brief Print all vertices
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
        /// @brief It determines the existence of the provided vertex in the graph.
        /// @param vertex This will be searched for.
        /// @return `true` or `false` based on existence of provided vertex in the graph. 
        bool vertexExist(const string& vertex){
                return adjList.count(vertex) == 1;
        }
        /// @brief It determines the non-existence of the provided vertex in the graph.
        /// @param vertex This will be verified to be non existing.
        /// @return `true` or `false`
        bool vertexDoesntExist(const string& vertex){
                return adjList.count(vertex) == 0;
        }
};
