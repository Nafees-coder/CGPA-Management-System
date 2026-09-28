#include "Student.h"
#include <iostream>
#include <iomanip>

Student::Student(string r, string n) {
    rollNo = r;
    name = n;
}

string Student::getRollNo() {
    return rollNo;
}

string Student::getName() {
    return name;
}

void Student::addCourse(Course c) {
    courses.push_back(c);
}

double Student::calculateGPA() {
    if (courses.empty()) return 0.0;

    double totalPoints = 0.0;
    int totalCredits = 0;

    for (auto c : courses) {
        totalPoints += (c.getGradePoint() * c.getCreditHours());
        totalCredits += c.getCreditHours();
    }

    if (totalCredits == 0) return 0.0;
    return totalPoints / totalCredits;
}

void Student::displayReportCard() {
    cout << "\n============================================\n";
    cout << "Roll No: " << rollNo << " | Name: " << name << "\n";
    cout << "--------------------------------------------\n";
    cout << left << setw(10) << "Code"
         << setw(20) << "Course Name"
         << setw(8)  << "Cr.Hr"
         << setw(8)  << "Marks"
         << setw(6)  << "GP\n";
    cout << "--------------------------------------------\n";

    for (auto c : courses) {
        cout << left << setw(10) << c.getCode()
             << setw(20) << c.getName()
             << setw(8)  << c.getCreditHours()
             << setw(8)  << c.getMarks()
             << fixed << setprecision(2) << setw(6) << c.getGradePoint() << "\n";
    }
    cout << "--------------------------------------------\n";
    cout << "Semester GPA: " << fixed << setprecision(2) << calculateGPA() << "\n";
    cout << "============================================\n";
}

string Student::serialize() {
    string data = rollNo + "|" + name + "|" + to_string(courses.size());
    for (auto c : courses) {
        data += "|" + c.getCode() + "," + c.getName() + "," +
                to_string(c.getCreditHours()) + "," + to_string(c.getMarks());
    }
    return data;
}