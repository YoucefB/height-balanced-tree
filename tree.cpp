#include <iostream>
#include <string>
#include <regex>
#include "tree.h"
#include "node.cpp"


using namespace std;


Node* Tree::getNode(Node* root, string data) {
    if (root != NULL) {
        if (root->data == data) {
            return root;
        } else {
            Node *v = getNode(root->left, data);
            if (v != NULL) {
                return v;
            } else {
                Node *v = getNode(root->right, data);
                if (v != NULL) {
                    return v;
                } else {
                    return NULL;
                }
            }
        }
    } else {
        return NULL;
    }
}

//===================================================

void Tree::addElememt(string line){
    regex e ("(.+)(l|r)(.+)");
        smatch m;
        if (regex_search(line, m, e)) { //valid input
            string a = m[1];
            string b = m[3];
            string choice = m[2];


            //b is child of a
            Node *parent = getNode(root, a);
            Node *child = getNode(root, b);

            if (parent == NULL) {
                //cout<< "parent is null"<<endl;
                parent = new Node(a);
                //the new root is parent
                if (root != NULL) {
                    //parent->left = root;
                    root = parent;
                    //cout<< "root has changed"<<endl;
                }
            }

            if (child == NULL) {
                //cout<< "child is null"<<endl;
                child = new Node(b);
            }

            //put o left or right
            if (choice == "l") {
                //cout<<"put on left"<<endl;
                parent->left = child;
            } else {
                //cout<<"put on right"<<endl;
                parent->right = child;
            }

            if(root == NULL){
                //cout<< "root is null"<<endl;
                root = parent;
            }

        } else {
            cout<<"invalid input : "<<line<<endl;
        }


}



/* The function Compute the "height" of a tree. Height is the number of
nodes along the longest path from the root node down to the farthest leaf node.*/
int Tree::height(Node* node){
    /* base case tree is empty */
    if (node == NULL)
        return 0;

    //height = 1 + max of left height and right heights
    return 1 + max(height(node->left), height(node->right));
}

//================================


/* function return true if tree is balanced  */
bool Tree::isBalanced(){
    return isBalanced(root);
}

bool Tree::isBalanced(Node* root){
    //the empty tree is balanced

    if (root == NULL) {
        return true;
    }

    cout <<"Checking node "<<root->data<<"..."<<endl;

    int leftHeight = height(root->left); // height of left subtree
    int rightHeight = height(root->right); // height of right subtree
    int d = abs(leftHeight - rightHeight);

    if (d <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    } else {
        return false;
    }
}


void Tree::print() {
    print(root);
}

void Tree::print(Node* root) {
    if (root != NULL) {
        print(root->left);
        cout<<root->data<<endl;
        print(root->right);
    }
}
