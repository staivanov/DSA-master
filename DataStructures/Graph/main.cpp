#include <iostream>
#include "../Graph/Graph.cpp"


int main() {
    //Graph with two vertices without an edge between them.
    Graph* graph = new Graph();
    string a = "A";
    graph->addVertex(a);
    string b = "B"; 
    graph->addVertex(b);
    graph->printGraph();
    //Graph with two vertices and edge between them.
    graph->addEdge(a, b);
    graph->printGraph();

    return 0;
}