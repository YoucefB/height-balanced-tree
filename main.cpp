#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <chrono>
#include <vector>
#include "tree.h"
#include "node.cpp"

using namespace std;
using namespace std::chrono;


string remove_space(string s) {
    string out = "";
    for (int i=0; i<s.length(); i++) {
        char c = s[i];
        if (c != ' ') {
            out = out + c;
        }
    }
    return out;
}


Tree readTreeFromFile(string input) {
    Tree tree;
    string line;
    ifstream myfile(input);
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            //remove spaces
            //cout<<line<<endl;
            line = remove_space(line);

            if (line=="") {
                continue;
            }

            tree.addElememt(line);
        }
        myfile.close();
    }
    return tree;
}

//==========================================================

int main(){
    cout<<"Select one option:"<<endl;
    cout<<"\t1 : Input from keyboard"<<endl;
    cout<<"\t2 : Input from a file (input.txt)"<<endl;

    int c;

    do {
        c = getchar();
        char ws = cin.get();
    } while ((c != '1') && (c != '2')) ;


    Tree tree;
    if (c == '1'){
        cout<<"How many nodes in the tree : ";
        int n = 0;
        cin>> n;
        char ws = cin.get(); //char
        for (int i=0; i<n - 1; i++) {
            string line;
            getline(cin, line);
            line = remove_space(line);
            tree.addElememt(line);
        }
    }

    if (c == '2'){
        cout<<"Loading data from file..."<<endl;
        tree = readTreeFromFile("input.txt");
    }

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    bool result = tree.isBalanced();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    if (result) {
        cout <<endl<<"Tree is balanced"<<endl;
    } else {
        cout <<endl<<"Tree is not balanced"<<endl;
    }

    cout <<endl<<"Checking the tree took : "<<duration<<" m.s"<<endl;

    //tree.print();

    return 0;
}
