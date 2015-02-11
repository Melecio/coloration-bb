#include "Graph.h"

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

/**
  * int r: is the number of colors used
  *  vector<Node *> *col_order: has the first valid coloration
  */
struct DsaturData {
    int r;
    std::vector<Node*> *col_order;
};

/**
 * Dsatur heuristic
 * @param A graph g
 * @return A DsaturData
 */

DsaturData dsatur(Graph *);

/**
 * Comparition function for sorting nodes by degree
 * @param Node *a
 * @param Node *b
 * @return true, if a has higher degree than b. False in any other case
 */

bool degree_compare(Node *, Node *);

/**
 * Comparition function for sorting nodes by saturation degree and other rules 
 * @param Node *a
 * @param Node *b
 * @return true, if a has to be place before b. False in any other case
 */

bool dsatur_compare(Node *, Node *);

/**
 * Returns the number of nodes of a cloque
 * @param DsaturData data
 * @return Number of nodes (w) in the clique between 0..w-1
 */

int get_clique_size(DsaturData d);

/**
 * Returns the chromatic color of a graph with Brelaz algorithm
 * @param Graph *graph
 * @param DsaturData data
 * @returns chromatic color of a graph
 */

int Brelaz(Graph *graph, DsaturData data);

/**
 * Tells if a graph has a valid coloration
 * @param Graph *graph
 * @returns true if graph has a valid coloration. False in any other case
 */

bool isValidColoration(std::vector<Node*> *nodes);

/**
 * Tells if a sequence of node between 0 and w-1 is a clique
 * @param vector<nodes *> *nodes  (nodes)
 * @param int w 
 * @returns True, if the sequence 0, 1, ..., w-1 is a clique. 
 *          False in any other case
 */

bool isClique(std::vector<Node*> *, int);

/**
 * Sets label
 * @param vector<bool> *labels 
 * @param vector<nodes *> *nodes  (nodes)
 * @param int k   (delimiter the partial solution)
 * Sets to true labels between 0..k-1 that achieve the properties
 */

void set_label(std::vector<bool> *labels, std::vector<Node *> *nodes, int k); 


#endif // ALGORITHMS_H
