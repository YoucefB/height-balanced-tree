#include <iostream>
#include "node.cpp"

using namespace std;

#ifndef TREE
#define TREE

class Tree {
private:
    Node* getNode(Node* root, string data);
    int height(Node* node);
    bool isBalanced(Node* root);
    void print(Node* root);
public:
    Node *root = NULL;
    void addElememt(string line);
    bool isBalanced();
    void print();
};

#endif // TREE

