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
        /** List of nodes */
        std::vector<Node*> *nodes;
    public:
        /** * Class Construnctor */
        Graph();
        /** * Class Construnctor */
        Graph(int);
        /** * Class Destructor */
        ~Graph();
        /**
          * Returns the nodes
          * @return the list of nodes
          */

        std::vector<Node*> *getNodes();
        /**
          * Returns the number of nodes of the graph 
          * @return the number of nodes
          */
        size_t size();
        /**
          * Add edge (a, b) to graph
          * @param int a
          * @param int b
          */
        void addEdge(int, int);
        /** * Returns the string representation of the graph */
        std::string toString();
};

#endif // GRAPH_H
