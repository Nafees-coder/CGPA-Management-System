#pragma once
#include <string>
using namespace std;

class Course {
private:
    string courseCode;
    string courseName;
    int creditHours;
    double marks;

public:
    // Constructor
    Course(string code = "", string name = "", int ch = 3, double m = 0.0);

    // Getters
    int getCreditHours();
    double getMarks();
    string getCode();
    string getName();

    // Logic method
    double getGradePoint();
};