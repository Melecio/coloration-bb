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

int Node::getId() { return this->id; }

void Node::setId(int id) { this->id = id; }

int Node::getColor() { return this->color; }

int Node::getSaturDegree() { return this->satur_degree; }

void Node::setColor(int color) { this->color = color; }

int Node::getUncolDegree() {
    int uncol_degree = 0;
    std::map<int,Node*>::iterator it = this->adjecents->begin();

    for(; it != this->adjecents->end(); ++it) {
        Node *current_node = it->second;
        if (!current_node->isColored())
            uncol_degree++;
    }

    return uncol_degree;
}

void Node::addAdjacent(Node *a) {
    std::pair<std::map<int,Node*>::iterator,bool> ret;
    ret = this->adjecents->insert(std::pair<int, Node*>(a->getId(),a));
    if (!ret.second) {
        std::cout << "Error inserting element into map" << std::endl;
    }
    this->degree++;
}

std::string Node::toString() {
    std::string str = "";

    str += "Nodo #" + std::to_string(this->id+1) + "\n";
    str += "    con " + std::to_string(this->degree) + " vecinos:\n";

    std::map<int,Node*>::iterator it = this->adjecents->begin();
    for(; it != this->adjecents->end(); ++it) {
        Node *current_node = it->second;
        str += "        " + std::to_string(current_node->getId()+1) + "\n";
    }

    return str;
}

bool Node::isColored() { return this->color != -1; }
