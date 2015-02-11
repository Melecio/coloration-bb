#include <map>
#include <vector>

#ifndef NODE_H
#define NODE_H

class Node {
    private:
        int id;
        int degree;
        int uncol_degree = 0;
        int satur_degree = 0;
        int color = -1;  // -1 means it has not been colored yet
        std::map<int,Node*> *adjecents;
        std::vector<bool> *colors;
    public:
        /** * Class Constructor */
        Node() = default;
        /** * Class Constructor */
        Node(int);
        /** * Class Constructor */
        Node(int, int, int);
        /** * Class Destructor */
        ~Node();

        /**
         * Returns the number of nodes adjacent this node
         * @return number of nodes adjacent
         */
        int getDegree();
        /** 
          * Returns its id
          * @return its id  
          */
       int getId();
        /** 
          * Sets an id
          */
        void setId(int);
        /**
          * Returns its color
          * @returns its color
          */
        int getColor();
        /**
          * Sets the lower color that can be selected
          * @returns the color
          */
        int setColor();
        /**
          * Sets i as the color to the node 
          * @param int i (color)
          */
        void setColor(int);
        /**
          * Returns the list of nodes that are adjacents to it 
          * @returns list of adjacents nodes
          */
        std::map<int, Node*> *getAdjacents(); 
        /**
          * Tells the number of adjacents that doesn't have been colored
          * @returns the number of adjacents that doesn't have been colored
          */
        int getUncolDegree();
        /**
          * Returns the saturation degree
          * @returns saturation degree
          */
        int getSaturDegree();
        /**
          * Increments the saturation degree if there isn't any adjacent that 
          * already has the color
          * @param int color (color)
          */
        void setSaturation(int color);
        /**
          * Add a node as adjacent
          * @param Node *a (node to be added as adjacent)
          */
        void addAdjacent(Node *);
        /**
          * Check if a node is adjacent
          * @param Node *n1 
          * @return true, if n1 is adjacent. False, in any other case
          */
        bool isAdjacent(Node *);
        /**
          * Check if a node is adjacent
          * @param int x  (id of some node)
          * @return true, if x is adjacent. False, in any other case
          */
        bool isAdjacent(int);
        /**
         * Returns printable information about the node and its adjacent nodes
         * @return A string with all the information
         */
        std::string toString();
        /**
          * Checks if is colored
          * @return true, if this color > 0. false in any other case
          */
        bool isColored();
};

#endif // NODE_H
