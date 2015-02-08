#include <vector>
#include <cstddef>
#include <iostream>
#include "Node.h"

#ifndef GRAPH_H
#define GRAPH_H

/**
 * Graph class
 */
class Graph {
    private:
        std::vector<Node*> *nodes;
    public:
        Graph();
        Graph(int);
        ~Graph();

        std::vector<Node*> *getNodes();

        size_t size();
        void addEdge(int, int);
        std::string toString();
};

#endif // GRAPH_H
