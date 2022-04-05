#include <iostream>
#include <string>

#include "BinarySearchTree.cpp"
#include "SeparateChain.cpp"
#include "Student.cpp"

using namespace std;

int main() {
    cout << "Assignment 04 Nick Voss:" << endl;
//    BinarySearchTree<int> tree;
//
    Student<string> nick("Nick", "Voss", "Information Technology", "4.0");
    Student<string> bob("Robert", "Ross", "Information Technology", "2.4");
    Student<string> rachel("Rachel", "Montano", "Business", "3.4");
//
//    tree.insert(5, nick);
//    tree.insert(15, bob);
//    tree.insert(65, rachel);

   Student<string> nickUpdated("Nick", "Voss", "Art", "1.0");
//    tree.update(5, nickUpdated);
//    tree.printNodeInfo(5);

//    tree.printTree();

    HashTable<int> t;

    t.insert(5, nick);
    t.insert(102, bob);
    t.insert(77, rachel);

    cout << "ID 5 before: " << endl;
    t.printNodeInfo(5);

    t.update(5, nickUpdated);

    cout << "ID 5 after: " << endl;
    t.printNodeInfo(5);
    cout << "Printing entire hash:" << endl;
    //table.displayHash();
    return 0;
}