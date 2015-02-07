#include <iostream>
#include "Graph.h"

Graph::Graph() {
    // this->nodes.reserve();
    this->nodes.push_back(new Node(20));
    // std::cout << this->nodes.size() << std::endl;
}

Graph::Graph(unsigned size) {
    this->nodes.reserve(size);
    for(unsigned i = 0; i < size; ++i) {
        this->nodes.push_back(new Node(0));
    }

}

Graph::~Graph() {
    for(unsigned i = 0; i < this->nodes.size(); ++i) {
        delete this->nodes[i];
    }
}

size_t Graph::size() {
    return this->nodes.size();
}
