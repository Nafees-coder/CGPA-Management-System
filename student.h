#pragma once
#include <string>
#include <vector>
#include "Course.h"
using namespace std;

class Student {
private:
    string rollNo;
    string name;
    vector<Course> courses;

public:
    Student(string r = "", string n = "");

    string getRollNo();
    string getName();
    void addCourse(Course c);
    double calculateGPA();
    void displayReportCard();
    string serialize();
};