#include <vector>
#include <cstddef>
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
        Graph(unsigned);
        ~Graph();

        size_t size();
};

#endif // GRAPH_H
