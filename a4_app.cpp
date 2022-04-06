#include <iostream>
#include <string>
#include <fstream>

#include "BinarySearchTree.cpp"
#include "SeparateChain.cpp"
#include "Student.cpp"

using namespace std;

void readFromFile(HashTable<int> &table) {
    ifstream file("enroll_test.txt");
    string studentID;
    string firstName;
    string lastName;
    string dept;
    string gpa;

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, studentID, ' ');
            getline(file, firstName, ' ');
            getline(file, lastName, ' ');
            getline(file, dept, ' ');
            getline(file, gpa, ' ');

            Student<string> student(firstName, lastName, dept, gpa);
            table.insert(stoi(studentID), student);
        }
        file.close();
    } else {
        cout << "Couldn't find the file enroll_test.txt!" << endl;
    }
}

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

    Student<string> edward("Edward", "Snowden", "Cyber Security", "3.8");
    Student<string> donald("Donald", "Duck", "Chemistry", "3.0");

    t.insert(5, nick);
    t.insert(102, bob);
    t.insert(77, rachel);
    t.insert(155, edward);
    t.insert(91, donald);

    cout << "ID 5 before: " << endl;
    t.printNodeInfo(5);

    t.update(5, nickUpdated);

    cout << "ID 5 after: " << endl;
    t.printNodeInfo(5);
    cout << "Printing entire hash:" << endl;
    t.displayHash();
    return 0;
}