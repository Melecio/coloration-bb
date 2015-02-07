#include <iostream>
#include "Node.h"

Node::Node(int degree) {
    this->degree = degree;
    this->adjecents = new std::map<int,Node*>();
}

Node::Node(int degree, int id) {
    this->degree = degree;
    this->id = id;
    this->adjecents = new std::map<int,Node*>();
}

Node::~Node() {
    delete adjecents;
}

int Node::getDegree() { return this->degree; }

void Node::setDegree(int degree) { this->degree = degree; }

int Node::getId() { return this->id; }

void Node::setId(int id) { this->id = id; }

int Node::getColor() { return this->color; }

void Node::setColor(int color) { this->color = color; }

void Node::addAdjacent(Node *a) {
    std::pair<std::map<int,Node*>::iterator,bool> ret;
    ret = this->adjecents->insert(std::pair<int, Node*>(a->getId(),a));
    if (!ret.second) {
        std::cout << "Error inserting element into map" << std::endl;
    }
}

std::string Node::toString() {
    std::string str = "";

    str += "Nodo #" + std::to_string(this->id+1) + "\n";
    str += "    con " + std::to_string(this->adjecents->size()) + " vecinos:\n";

    std::map<int,Node*>::iterator it = this->adjecents->begin();
    for(; it != this->adjecents->end(); ++it) {
        Node *current_node = it->second;
        str += "        " + std::to_string(current_node->getId()+1) + "\n";
    }

    return str;
}

Node* Node::getFirstAdjecent() {
    Node *a = this->adjecents->begin()->second;

    return a;
}

