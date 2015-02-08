#include "Graph.h"

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

struct DsaturData {
    int w;
};

bool dsatur_compare(Node *a, Node *b) {
    if (a->getSaturDegree() != b->getSaturDegree()) {
        return a->getSaturDegree() < b->getSaturDegree();
    } else {
        return a->getUncolDegree() < b->getUncolDegree();
    }
}

#endif // ALGORITHMS_H
