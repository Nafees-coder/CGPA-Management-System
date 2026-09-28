#pragma once
#include <vector>
#include <string>
#include "Student.h"
using namespace std;

class StudentManager {
private:
    vector<Student> students;
    string fileName = "students_db.txt";

public:
    void addStudent();
    void displayAll();
    void searchByRoll();
    void saveToFile();
};