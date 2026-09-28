#include "Course.h"

// Constructor: sets up a course with its code, name, credit hours, marks
Course::Course(string code, string name, int ch, double m) {
    courseCode = code;
    courseName = name;
    creditHours = ch;
    marks = m;
}

int Course::getCreditHours() {
    return creditHours;
}

double Course::getMarks() {
    return marks;
}

string Course::getCode() {
    return courseCode;
}

string Course::getName() {
    return courseName;
}

double Course::getGradePoint() {
    if (marks >= 85) return 4.00;
    if (marks >= 80) return 3.66;
    if (marks >= 75) return 3.33;
    if (marks >= 70) return 3.00;
    if (marks >= 65) return 2.66;
    if (marks >= 60) return 2.00;
    if (marks >= 50) return 1.00;
    return 0.00;
}