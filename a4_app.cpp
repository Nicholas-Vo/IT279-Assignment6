#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <sstream>

#include "BinarySearchTree.cpp"
#include "SeparateChain.cpp"
#include "Student.cpp"

using namespace std;

int main() {
    cout << "Assignment 04 Nick Voss:" << endl;
    BinarySearchTree<int> tree;

    Student<string> nick("Nick", "Voss", "Information Technology", "4.0");

    tree.insert(5, nick);
    tree.printNodeInfo(5);
    return 0;
}