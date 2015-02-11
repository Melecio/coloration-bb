#include <iostream>
#include <cstdlib>
#include <cassert>
#include "utils.h"
#include "Graph.h"
#include "algorithms.h"


int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cout << "TODO print usage" << std::endl;
        exit(1);
    }

    std::cout << "----------------" << std::endl;
    std::cout << argv[1] << std::endl;

    Graph *g = parse_DIMACS(argv[1]);
    if (g == NULL) exit(1);

    DsaturData data = dsatur(g);


    int w = get_clique_size(data);

    assert(isValidColoration(data.col_order));
    assert(isClique(data.col_order, w));

    std::cout << data.r << std::endl;
    std::cout << "coloracion = " <<  Brelaz(g, data) << std::endl;
    std::cout << "----------------" << std::endl;

    delete g;
}

