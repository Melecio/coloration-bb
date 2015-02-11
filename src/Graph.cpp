#include <iostream>
#include "Graph.h"

/**
  * Class Construnctor 
  */

Graph::Graph() {
    this->nodes = new std::vector<Node*>();
}

/**
  * Class Construnctor
  */

Graph::Graph(int size) {
    this->nodes = new std::vector<Node*>();
    for(int i = 0; i < size; ++i) {
        this->nodes->push_back(new Node(0, i, size));
    }
}

/**
  * Class Destructor
  */

Graph::~Graph() {
    std::vector<Node*>::iterator it = this->nodes->begin();

    for(; it < this->nodes->end(); ++it) {
        delete (*it);
    }

    delete this->nodes;
}

/**
  * Returns the nodes
  * @return the list of nodes
  */

std::vector<Node*> *Graph::getNodes() { return this->nodes; }

/**
  * Returns the number of nodes of the graph 
  * @return the number of nodes
  */

size_t Graph::size() {
    return this->nodes->size();
}

/**
  * Add edge (a, b) to graph
  * @param int a
  * @param int b
  */

void Graph::addEdge(int a, int b) {
    if(a == b)
        return;

    std::vector<Node *> *v = this->nodes;
    Node *a_node = (*v)[a-1];
    Node *b_node = (*v)[b-1];
    a_node->addAdjacent(b_node);
    b_node->addAdjacent(a_node);
}

/**
  * Returns the string representation of the graph
  */

std::string Graph::toString() {
    std::string str = "";

    str += "Grafo con " + std::to_string(this->nodes->size());
    str += " con nodos:\n";
    for(unsigned i = 0; i < this->nodes->size(); ++i) {
        std::vector<Node *> *v = this->nodes;
        str += (*v)[i]->toString();
    }

    return str;
}
