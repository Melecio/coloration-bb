#include <map>

#ifndef NODE_H
#define NODE_H

class Node {
    private:
        int id;
        int degree;
        int color = -1;
        std::map<int,Node*> *adjecents;
    public:
        Node() = default;
        Node(int);
        Node(int, int);
        ~Node();

        int getDegree();

        void setDegree(int);

        int getId();

        void setId(int);

        int getColor();

        void setColor(int);

        void addAdjacent(Node *);

        std::string toString();

        Node* getFirstAdjecent();
};

#endif // NODE_H
