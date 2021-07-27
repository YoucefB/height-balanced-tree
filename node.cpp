#include <string>

using namespace std;

#ifndef NODE
#define NODE

class Node {
    public:
        string data;
        Node* left;
        Node* right;

        //constructor
        Node(string d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

#endif // NODE
