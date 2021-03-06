#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include "Graph.h"
#ifndef UTILS_H
#define UTILS_H

/**
 * Parses the input file that should be on DIMACS format and builds the
 * corresponding graph representint the problem.
 * @param  file_name file in DIMACS format.
 * @return           A pointer to an object of Graph class or NULL if errors.
 */
Graph *parse_DIMACS(std::string file_name) {

    std::ifstream file(file_name);
    if (file.fail()) {
        std::cout << "File not found" << std::endl;
        return NULL;
    }

    Graph *g;
    std::string line;
    std::string pr_type;
    char line_label;
    long nodes, edges;

    while(std::getline(file, line)) {
        switch(line[0]) {
            // Ignore comments, new lines and lines at the end
            case 'c':
            case '\n':
            case '\0':
                break;
            case 'p':  // The problem description is found
                {
                    std::istringstream stream(line);
                    stream >> line_label >> pr_type >> nodes  >> edges;
                    g = new Graph(nodes);
                    break;
                }
            case 'e':  // Edge description is found
                {
                    // std::cout << line << std::endl;
                    std::istringstream stream(line);
                    int a,b;
                    stream >> line_label >> a >> b;
                    g->addEdge(a,b);
                    break;
                }
            default:
                break;
        }
    }

    return g;
}

#endif // UTILS_H
