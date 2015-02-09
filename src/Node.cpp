#include <iostream>
#include "Node.h"

Node::Node(int degree) {
    this->degree = degree;
    this->adjecents = new std::map<int,Node*>();
}

Node::Node(int degree, int id, int max_colors) {
    this->degree = degree;
    this->id = id;
    this->adjecents = new std::map<int,Node*>();
    this->colors    = new std::vector<bool>(max_colors+1, false);
}

Node::~Node() {
    delete adjecents;
    delete colors;
}

int Node::getDegree() { return this->degree; }

int Node::getId() { return this->id; }

void Node::setId(int id) { this->id = id; }

int Node::getColor() { return this->color; }

std::map<int, Node*> *Node::getAdjacents() { return this->adjecents; }

int Node::getSaturDegree() { return this->satur_degree; }

int Node::setColor() {
    int color = 0;

    std::vector<bool>::iterator it = this->colors->begin()+1;
    for(; it != this->colors->end(); ++it) {
        color++;
        if (!(*it)) {
            this->color = color;
            break;
        }
    }

    std::map<int,Node*>::iterator it2 = this->adjecents->begin();

    for(; it2 != this->adjecents->end(); ++it2) {
        it2->second->setSaturation(color);
    }

    return this->color;
}

void Node::setColor(int i) { this->color = i; }

void Node::setSaturation(int color) {
    std::vector<bool> *v = this->colors;
    if (!(*v)[color])
        satur_degree++;
    (*v)[color] = true;
}

int Node::getUncolDegree() {
    std::map<int,Node*>::iterator it = this->adjecents->begin();
    this->uncol_degree = 0;

    for(; it != this->adjecents->end(); ++it) {
        Node *current_node = it->second;
        if (!current_node->isColored())
            this->uncol_degree++;
    }

    return this->uncol_degree;
}

void Node::addAdjacent(Node *a) {
    std::pair<std::map<int,Node*>::iterator,bool> ret;
    ret = this->adjecents->insert(std::pair<int, Node*>(a->getId(),a));
    if (!ret.second) {
        std::cout << "Error inserting element into map" << std::endl;
    }
    this->degree++;
}

bool Node::isAdjacent(Node *n1) { return this->isAdjacent(n1->getId()); }

bool Node::isAdjacent(int x) { return adjecents->find(x) != adjecents->end(); }

std::string Node::toString() {
    std::string str = "";

    str += "Nodo #" + std::to_string(this->id+1) + "\n";
    str += "    con color: " + std::to_string(this->color) + "\n";
    str += "    con grado de saturacion: " + std::to_string(this->satur_degree) + "\n";
    str += "    con uncol degre: " + std::to_string(this->uncol_degree) + "\n";
    str += "    con " + std::to_string(this->degree) + " vecinos:\n";

    std::map<int,Node*>::iterator it = this->adjecents->begin();
    for(; it != this->adjecents->end(); ++it) {
        Node *current_node = it->second;
        str += "        " + std::to_string(current_node->getId()+1) + "\n";
    }

    return str;
}

bool Node::isColored() { return this->color != -1; }
