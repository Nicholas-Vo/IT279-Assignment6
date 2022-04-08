#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>

#include "BinarySearchTree.cpp"
#include "SeparateChain.cpp"
#include "Student.cpp"

using namespace std;

list<int> getIds(HashTable<int> &t, const string &fileName) {
    ifstream file("data/" + fileName);
    string studentID;

    stringstream stream;
    stream << file.rdbuf(); // Read buffer

    // list of ID, Student pairs to fill
    list<int> data;

    while (stream >> studentID) {
        //stream >> studentID; // Load data from stringstream
        data.push_back(stoi(studentID));
    }

    return data;
}

list<pair<int, Student<string>>> getStudents(HashTable<int> &t, const string &fileName) {
    ifstream file("data/" + fileName);
    string studentID, firstName, lastName, dept, gpa;

    stringstream stream;
    stream << file.rdbuf(); // Read buffer

    // list of ID, Student pairs to fill
    list<pair<int, Student<string>>> data;

    while (stream >> studentID >> firstName >> lastName >> dept >> gpa) {
        Student<string> student(firstName, lastName, dept, gpa);

        data.emplace_back(stoi(studentID), student);
    }

    file.close();
    return data;
}

int main() {
    cout << "Assignment 04 Nick Voss:" << endl;
    HashTable<int> table(7);

    // Question 4 part A
    for (auto &p: getStudents(table, "enroll_test.txt")) {
        table.insert(p.first, p.second);
    }
    cout << endl;

    // Question 4 part B & C
    cout << "Searching..." << endl;
    for (auto &id: getIds(table, "search_test1.txt")) {
        table.printNodeInfo(id);
    }
    cout << endl;

    cout << "Searching..." << endl;
    for (auto &id: getIds(table, "search_test2.txt")) {
        table.printNodeInfo(id);
    }
    cout << endl;

    // Question 4 part D
    cout << "Updated: " << endl;
    for (auto &p: getStudents(table, "update_test.txt")) {
        if (table.update(p.first, p.second)) {
            table.printNodeInfo(p.first);
        }
    }
    cout << endl;

    // Question 4 part E
    cout << "Deleted:" << endl;
    for (auto &id: getIds(table, "remove_test.txt")) {
        if (table.printNodeInfo(id)) {
            table.remove(id);
        }
    }
    cout << endl;

    // Question 4 part f
    cout << "Updated hash table: " << endl;
    table.displayHash();
    cout << endl;

    // Question 4 part g
    cout << "After emptying:" << endl;
    table.makeEmpty();
    table.displayHash();
    return 0;
}
























