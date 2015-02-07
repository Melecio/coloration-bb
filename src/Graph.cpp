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
        this->nodes->push_back(new Node(i));
    }
}

Graph::~Graph() {
    std::vector<Node*>::iterator it = this->nodes->begin();

    for(; it < this->nodes->end(); ++it) {
        delete (*it);
    }

    delete this->nodes;
}

size_t Graph::size() {
    return this->nodes->size();
}
