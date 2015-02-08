#include <algorithm>
#include "algorithms.h"

void dsatur(Graph *g) {
    std::vector<Node*> *nodes = g->getNodes();
    sort(nodes->begin(), nodes->end(), dsatur_compare);

    nodes->begin()->setColor(1);
}
