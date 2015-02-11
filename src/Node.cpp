#include <iostream>
#include "Node.h"
/** 
  * Class Construnctor 
  */
Node::Node(int degree) {
    this->degree = degree;
    this->adjecents = new std::map<int,Node*>();
}
/** 
  * Class Construnctor 
  */
Node::Node(int degree, int id, int max_colors) {
    this->degree = degree;
    this->id = id;
    this->adjecents = new std::map<int,Node*>();
    this->colors    = new std::vector<bool>(max_colors+1, false);
}
/** 
  * Class Destructor
  */
Node::~Node() {
    delete adjecents;
    delete colors;
}

/** 
  * Returns its degree 
  * @return its degree
  */

int Node::getDegree() { return this->degree; }

/** 
  * Returns its id
  * @return its id  
  */

int Node::getId() { return this->id; }
/** 
  * Sets an id
  */
void Node::setId(int id) { this->id = id; }

/**
  * Returns its color
  * @returns its color
  */

int Node::getColor() { return this->color; }

/**
  * Returns the list of nodes that are adjacents to it 
  * @returns list of adjacents nodes
  */

std::map<int, Node*> *Node::getAdjacents() { return this->adjecents; }

/**
  * Returns the saturation degree
  * @returns saturation degree
  */
int Node::getSaturDegree() { return this->satur_degree; }

/**
  * Sets the lower color that can be selected
  * @returns the color
  */

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

/**
  * Sets i as the color to the node 
  * @param int i (color)
  */

void Node::setColor(int i) { this->color = i; }

/**
  * Increments the saturation degree if there isn't any adjacent that 
  * already has the color
  * @param int color (color)
  */

void Node::setSaturation(int color) {
    std::vector<bool> *v = this->colors;
    if (!(*v)[color])
        satur_degree++;
    (*v)[color] = true;
}

/**
  * Tells the number of adjacents that doesn't have been colored
  * @returns the number of adjacents that doesn't have been colored
  */

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

/**
  * Add a node as adjacent
  * @param Node *a (node to be added as adjacent)
  */

void Node::addAdjacent(Node *a) {
    std::pair<std::map<int,Node*>::iterator,bool> ret;
    ret = this->adjecents->insert(std::pair<int, Node*>(a->getId(),a));
    if (ret.second) 
        this->degree++;
    
}

/**
  * Check if a node is adjacent
  * @param Node *n1 
  * @return true, if n1 is adjacent. False, in any other case
  */

bool Node::isAdjacent(Node *n1) { return this->isAdjacent(n1->getId()); }

/**
  * Check if a node is adjacent
  * @param int x  (id of some node)
  * @return true, if x is adjacent. False, in any other case
  */

bool Node::isAdjacent(int x) { return adjecents->find(x) != adjecents->end(); }

/**
  * Returns string representation of the node
  * @return string represenationt
  */

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

/**
  * Checks if is colored
  * @return true, if this color > 0. false in any other case
  */

bool Node::isColored() { return this->color > 0; }
