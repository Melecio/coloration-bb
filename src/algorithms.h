#include "Graph.h"

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

struct DsaturData {
    int r;
    std::vector<Node*> *col_order;
};

DsaturData dsatur(Graph *);

bool degree_compare(Node *, Node *);

bool dsatur_compare(Node *, Node *);

int get_clique_size(DsaturData d);

int Brelaz(Graph *graph, DsaturData data);

bool isValidColoration(std::vector<Node*> *nodes);

bool isClique(std::vector<Node*> *, int);

#endif // ALGORITHMS_H
