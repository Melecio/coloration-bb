#include <iostream>
#include "Graph.h"

Graph::Graph() {
    // this->nodes.reserve();
    // this->nodes.push_back(new Node(20));
    this->nodes = new std::vector<Node*>();
    // std::cout << this->nodes.size() << std::endl;
}

Graph::Graph(unsigned size) {
    // this->nodes.reserve(size);
    // for(unsigned i = 0; i < size; ++i) {
    //     this->nodes.push_back(new Node(0));
    // }
    this->nodes = new std::vector<Node*>();
    for(unsigned i = 0; i < size; ++i) {
        this->nodes->push_back(new Node(0, i));
    }
}

Graph::~Graph() {
    std::vector<Node*>::iterator it = this->nodes->begin();

    for(; it < this->nodes->end(); ++it) {
        delete (*it);
    }

    delete this->nodes;
}

std::vector<Node*> *Graph::getNodes() { return this->nodes; }

size_t Graph::size() {
    return this->nodes->size();
}

void Graph::addEdge(int a, int b) {
    std::vector<Node *> *v = this->nodes;
    Node *a_node = (*v)[a-1];
    Node *b_node = (*v)[b-1];
    // std::cout <<  "Agregando el arco: " << a_node->getId()+1 << ", " << b_node->getId()+1;
    // std::cout << std::endl;
    a_node->addAdjacent(b_node);
    b_node->addAdjacent(a_node);
}

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
