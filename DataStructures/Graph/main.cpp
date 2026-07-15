#include <iostream>
#include "../Graph/Graph.cpp"


int main() {

    Graph* graph = new Graph();
    string vertexA = "A";
    graph->addVertex(vertexA);
    graph->printGraph();




    return 0;
}