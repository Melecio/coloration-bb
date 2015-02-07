#ifndef NODE_H
#define NODE_H

class Node {
    private:
        int degree;
        int color;
    public:
        Node() = default;
        Node(int);
        Node(int, int);
        ~Node();

        int getDegree();

        void setDegree(int);

        int getColor();

        void setColor(int);

};

#endif // NODE_H
