#include <map>

#ifndef NODE_H
#define NODE_H

class Node {
    private:
        int id;
        int degree;
        int satur_degree = 0;
        int color = -1;  // -1 means it has not been colored yet
        std::map<int,Node*> *adjecents;
    public:
        Node() = default;
        Node(int);
        Node(int, int);
        ~Node();

        /**
         * Returns the number of nodes adjacent this node
         * @return number of nodes adjacent
         */
        int getDegree();

        /**
         * Returns the ID of this node
         * @return the ID of this node
         */
        int getId();

        void setId(int);

        int getColor();

        void setColor(int);

        int getUncolDegree();

        int getSaturDegree();

        void addAdjacent(Node *);

        /**
         * Returns printable information about the node and its adjacent nodes
         * @return A string with all the information
         */
        std::string toString();

        bool isColored();
};

#endif // NODE_H
