#include <cassert>
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


int get_clique_size(DsaturData data) {
    std::vector<Node*> *nodes = data.col_order;
    int d = 1;

    for(; d < nodes->size() and
        (*nodes)[d-1]->getColor() < (*nodes)[d]->getColor(); ++d);

    return d;
}


int get_uk(std::vector<Node *> *nodes, int k) {
    int imax = -1;
    for (unsigned i = 0; i < k; i++)
        imax = std::max(imax, (*nodes)[i]->getColor());
    return imax;
}

std::vector<int> *get_Uxk(std::vector<Node *> *nodes, int k, int imin) {
    std::vector<int> *aux = new std::vector<int>();
    for (int i = 0; i <= imin; i++)  aux->push_back(i);

    std::map<int, Node *> *adj = (*nodes)[k]->getAdjacents();
    std::map<int, Node *>::iterator it = adj->begin();

    for (; it != adj->end(); ++it) {
        int color = (*it).second->getColor();
        if (color <= imin)
            (*aux)[((*it).second)->getColor()] = -1;
    }

    std::vector<int> *Uxk = new std::vector<int>();
    for (int i = 0; i <= imin; i++)
        if ((*aux)[i] != -1)
            Uxk->push_back((*aux)[i]);

    return Uxk;
}

void set_label(std::vector<int> *labels, std::vector<Node *> *nodes, int k) {
    Node *Xk = (*nodes)[k];   //k-th node
    std::vector<bool> colors;
    colors.assign(nodes->size(), false);
    for (int i = 0; i < k; i++) {  //smaller rank property
        if (Xk->isAdjacent( (*nodes)[k] )) {  //adjacent to Xk property
            //introduces the color for the connected component
            if (! colors[ (*nodes)[k]->getColor() ])
                (*labels)[ (*nodes)[k]->getId() ] = k;
        }
    }
}

void Brelaz(Graph *graph, DsaturData data) {
    std::vector<Node*> *nodes = data.col_order;
    int w = get_clique_size(data); //number of vertex of the clique
    int q = data.r;   //max color used
    if (q + 1 == w) return;
    int k = w;        //because indexed in 0
    bool back = false;
    std::vector< std::vector<int> *> *nodes_uxk = new std::vector< std::vector<int> *>();
    nodes_uxk->assign(graph->size(), NULL);

    //labels for every node
    //use it with node->getId() like labels[ node->getId() ]
    std::vector<int> *labels = new std::vector<int>();
    labels->assign(graph->size(), -1);

    while (1) {
        //this is for taking track of the amount of colors used
        //which is the maximum color used
        int max_colors = q;
        if (! back) {
            int uk = get_uk(nodes, k);
           (*nodes_uxk)[k] = get_Uxk(nodes, k, std::min(uk + 1, q -1));  //calculate Uxk and save it
        } else {
            int color = (*nodes)[k]->getColor();
            std::vector<int> *Uxk = (*nodes_uxk)[k];        //Uxk previously calculated
            std::vector<int>::iterator it = Uxk->begin();
            for (; it != Uxk->end(); ++it) if ((*it) == color) break;  //getting where is the color of k-th node
            Uxk->erase(it);   //... and delete it
            (* labels)[ (*nodes)[k]->getId() ]  = -1; //delete label
        }
        std::vector<int> *Uxk = (*nodes_uxk)[k];
        if (! Uxk->empty()) {
            max_colors = std::max(max_colors, Uxk->front());
            (*nodes)[k]->setColor( Uxk->front() );    //the color is the minimal of all the colors
            k = k + 1;
            int sz = graph->size();
            if (k == sz) {  //not k > n, because colored nodes goes from 0..n-1
                q = max_colors;
                if (q == w - 1) return;
                k = 0;  //determine k as the minimal rank among all q-colored
                for (; k < sz && (*nodes)[k]->getColor() != q; k++);
                for (int i = k; i < sz; i++) (*labels)[ (*nodes)[i]->getId() ] = -1;
            } else {
                back = false;
            }
        } else {
            back = true;
        }
        if (back) {
            set_label(labels, nodes, k);
            k = graph->size() - 1;
            for (; k >= 0 && ((*labels)[ (*nodes)[k]->getId() ] != -1); k--);
            assert(k>=0);
            //k is in the clique, so you can't get a better solution
            if (k <= w - 1) return;
        }
    }
}
