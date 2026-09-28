#include "StudentManager.h"
#include <iostream>
#include <fstream>

void StudentManager::addStudent() {
    string roll, name;
    cout << "Enter Roll Number: ";
    cin >> roll;
    cin.ignore();
    cout << "Enter Full Name: ";
    getline(cin, name);

    Student s(roll, name);

    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; i++) {
        string code, cname;
        int ch;
        double marks;
        cout << "\n[Course " << i + 1 << "]\n";
        cout << "Code: "; cin >> code;
        cin.ignore();
        cout << "Title: "; getline(cin, cname);
        cout << "Credit Hours: "; cin >> ch;
        cout << "Marks: "; cin >> marks;

        Course c(code, cname, ch, marks);
        s.addCourse(c);
    }

    students.push_back(s);
    cout << "\n[Done] Student added successfully!\n";
}

void StudentManager::displayAll() {
    if (students.empty()) {
        cout << "\nNo records found.\n";
        return;
    }
    for (auto s : students) {
        s.displayReportCard();
    }
}

void StudentManager::searchByRoll() {
    string roll;
    cout << "Enter Roll Number to search: ";
    cin >> roll;

    for (auto s : students) {
        if (s.getRollNo() == roll) {
            s.displayReportCard();
            return;
        }
    }
    cout << "\n[!] Student not found.\n";
}

void StudentManager::saveToFile() {
    ofstream out(fileName);
    if (!out) {
        cerr << "Error writing to file.\n";
        return;
    }
    for (auto s : students) {
        out << s.serialize() << "\n";
    }
    out.close();
    cout << "[Done] Data saved to " << fileName << "\n";
}