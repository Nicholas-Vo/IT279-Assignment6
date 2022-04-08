#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>

#include "BinarySearchTree.cpp"
#include "SeparateChain.cpp"
#include "Student.cpp"

using namespace std;

void insertStudentsFromFile(HashTable<int> &table, const string &fileName) {
    ifstream file(fileName);
    string studentID, firstName, lastName, dept, gpa;

    stringstream stream;
    stream << file.rdbuf(); // Read buffer

    while (stream.good()) {
        stream >> studentID; // Load data from stringstream
        stream >> firstName;
        stream >> lastName;
        stream >> dept;
        stream >> gpa;

        Student<string> student(firstName, lastName, dept, gpa);
        table.insert(stoi(studentID), student);
    }

    file.close();
    cout << endl;
    table.displayHash();
    cout << endl;
}

void readStudentIDFromFile(HashTable<int> &table, const string &fileName) {
    ifstream file(fileName);
    string studentID;
    stringstream stream;
    stream << file.rdbuf(); // Read buffer

    cout << "Search results: " << endl;
    while (stream >> studentID) {
        table.printNodeInfo(stoi(studentID));
    }

    file.close();
    cout << endl;
}

void updateStudents(HashTable<int> &table, const string &fileName) {
    ifstream file(fileName);
    string studentID, firstName, lastName, dept, gpa;

    stringstream stream;
    stream << file.rdbuf(); // Read buffer

    cout << "Students who were successfully updated: " << endl;
    while (stream.good()) {
        stream >> studentID; // Load data from stringstream
        stream >> firstName;
        stream >> lastName;
        stream >> dept;
        stream >> gpa;

        Student<string> student(firstName, lastName, dept, gpa);

        int theID = stoi(studentID);
        if (table.update(theID, student)) {
            table.printNodeInfo(theID);
        }
    }

    file.close();
    cout << endl;
}

int main() {
    cout << "Assignment 04 Nick Voss:" << endl;
    HashTable<int> table(7);

    // Question 4 part A
    insertStudentsFromFile(table, "data/enroll_test.txt");

    // Question 4 part B & C
    readStudentIDFromFile(table, "data/search_test1.txt");
    readStudentIDFromFile(table, "data/search_test2.txt");

    // Question 4 part D
    updateStudents(table, "data/update_test.txt");
    return 0;
}
























