#include <algorithm>
#include "algorithms.h"

DsaturData dsatur(Graph *g) {
    int max_color = -1;
    std::vector<Node*> *nodes = new std::vector<Node*>();
    std::vector<Node*> *col_order = new std::vector<Node*>();

    for(unsigned i = 0; i < g->size(); ++i) {
        nodes->push_back((*g->getNodes())[i]);
    }
    sort(nodes->begin(), nodes->end(), &degree_compare);
    std::vector<Node*>::iterator it = nodes->begin();

    (*it)->setColor();
    col_order->push_back(*it);
    nodes->erase(it);

    for(unsigned i = 0; i < g->size()-1; ++i) {
        sort(nodes->begin(), nodes->end(), &dsatur_compare);
        std::vector<Node*>::iterator it = nodes->begin();

        // std::cout << "--------------------" << std::endl;
        // for(unsigned i = 0; i < nodes->size(); ++i) {
        //     std::cout << (*nodes)[i]->toString() << std::endl;
        // }
        // std::cout << "--------------------" << std::endl;

        max_color = std::max((*it)->setColor(), max_color);
        col_order->push_back(*it);
        nodes->erase(it);
    }

    DsaturData data;
    data.col_order = col_order;
    data.r = max_color;

    return data;
}

bool degree_compare(Node *a, Node *b) {
    return a->getDegree() > b->getDegree();
}

bool dsatur_compare(Node *a, Node *b) {
    if (b->isColored())
        return true;
    if (a->isColored())
        return false;

    if (a->getSaturDegree() != b->getSaturDegree()) {
        return a->getSaturDegree() > b->getSaturDegree();
    } else {
        return a->getUncolDegree() > b->getUncolDegree();
    }
}

