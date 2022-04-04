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

// TODO: update() and printTree()

int main() {
    cout << "Assignment 04 Nick Voss:" << endl;
    BinarySearchTree<int> tree;

    Student<string> nick("Nick", "Voss", "Information Technology", "4.0");
    Student<string> bob("Robert", "Ross", "Information Technology", "2.4");
    Student<string> rachel("Rachel", "Montano", "Business", "3.4");

    tree.insert(5, nick);
    tree.insert(15, bob);
    tree.insert(65, rachel);

    Student<string> nickUpdated("Nick", "Voss", "Art", "1.0");
    tree.update(5, nickUpdated);
    tree.printNodeInfo(5);
    return 0;
}