#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>
#include <utility>

using namespace std;

template<typename Comparable>
class Student {
private:
    string fname, lname, department;
    string gpa;

public:

    /*
     * std::move is used to indicate that an object t may be "moved from",
     * i.e. allowing the efficient transfer of resources from t to another object.
     */
    Student(string firstName, string lastName, string department, string gpa)
            : fname{std::move(firstName)}, lname{std::move(lastName)},
              department{std::move(department)}, gpa{std::move(gpa)} {
    }

    string getFirstName();

    string getLastName();

    string getDepartment();

    string getGPA();

    void setFirstName(Comparable name);

    void setLastName(Comparable name);

    void setDepartment(Comparable dept);

    void setGPA(Comparable gpa);
};

#endif