#include <iostream>
#include <cstdlib>
#include "utils.h"
#include "Graph.h"
#include "algorithms.h"


int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cout << "TODO print usage" << std::endl;
        exit(1);
    }

    Graph *g = parse_DIMACS(argv[1]);
    if (g == NULL) exit(1);

    DsaturData data = dsatur(g);

    std::cout << data.r+1 << std::endl;


    // std::cout << g->toString() << std::endl;

    delete g;
}

