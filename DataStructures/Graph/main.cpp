#include <iostream>
#include "../Graph/Graph.cpp"


int main() {
    Graph* graph = new Graph();
    
    string a = "A";
    graph->addVertex(a);
    string b = "B";
    graph->addVertex(b);
    string c = "C";
    graph->addVertex(c);
    string d = "D";
    graph->addVertex(d);


    graph->addEdge(a, b);
    graph->addEdge(a, c);
    graph->addEdge(a,d);
    graph->addEdge(b, d);
    graph->addEdge(c, d);

    graph->printGraph();

    //Demo for removing a vertex.

    graph->removeVertex(d);
    graph->printGraph();

    return 0;
}