#include <iostream>
#include <cstdlib>
#include "utils.h"
#include "Graph.h"


int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cout << "TODO print usage" << std::endl;
        exit(1);
    }

    Graph *g = parse_DIMACS(argv[1]);
    if (g == NULL) exit(1);

    std::cout << g->toString() << std::endl;

    delete g;
}

