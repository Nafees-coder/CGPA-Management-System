#include <iostream>
#include "StudentManager.h"
using namespace std;

int main() {
    StudentManager sm;
    int choice;

    do {
        cout << "\n=== STUDENT CGPA MANAGEMENT SYSTEM ===\n";
        cout << "1. Add New Student Record\n";
        cout << "2. Display All Students & GPAs\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Save Records to File\n";
        cout << "5. Exit\n";
        cout << "Enter choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: sm.addStudent(); break;
            case 2: sm.displayAll(); break;
            case 3: sm.searchByRoll(); break;
            case 4: sm.saveToFile(); break;
            case 5: cout << "Exiting system...\n"; break;
            default: cout << "Invalid option! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}