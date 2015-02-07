#include "Node.h"

Node::Node(int degree) {
    this->degree = degree;
}

Node::Node(int degree, int color) {
    this->degree = degree;
    this->color = color;
}

Node::~Node() {}

int Node::getDegree() { return this->degree; }

void Node::setDegree(int degree) { this->degree = degree; }

int Node::getColor() { return this->color; }

void Node::setColor(int color) { this->color = color; }
