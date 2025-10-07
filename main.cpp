#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Student class definition
class Student {
public:
    string name;
    string roll_number;
    string department;
    double gpa;
    string contact;

    Student(string n, string r, string d, double g, string c)
        : name(n), roll_number(r), department(d), gpa(g), contact(c) {}
};

// Display & Search Functions
void display_all_students(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records found!" << endl;
        return;
    }
    cout << "\n" << setw(20) << left << "Name" << setw(15) << "Roll Number" << setw(20) << "Department"
         << setw(10) << "GPA" << setw(20) << "Contact" << endl;
    cout << string(85, '-') << endl;
    for (const auto& student : students) {
        cout << setw(20) << left << student.name << setw(15) << student.roll_number << setw(20) << student.department
             << setw(10) << fixed << setprecision(2) << student.gpa << setw(20) << student.contact << endl;
    }
}

void display_student_by_roll(const vector<Student>& students) {
    string roll_number;
    cout << "Enter roll number to view: ";
    cin.ignore(1, '\n');
    getline(cin, roll_number);

    for (const auto& student : students) {
        if (student.roll_number == roll_number) {
            cout << "\n" << setw(20) << left << "Name" << setw(15) << "Roll Number" << setw(20) << "Department"
                 << setw(10) << "GPA" << setw(20) << "Contact" << endl;
            cout << string(85, '-') << endl;
            cout << setw(20) << left << student.name << setw(15) << student.roll_number << setw(20) << student.department
                 << setw(10) << fixed << setprecision(2) << student.gpa << setw(20) << student.contact << endl;
            return;
        }
    }
    cout << "Error: Student not found!" << endl;
}

void search_students(const vector<Student>& students) {
    string query;
    cout << "Enter name or department to search: ";
    cin.ignore(1, '\n');
    getline(cin, query);
    string query_lower = query;
    transform(query_lower.begin(), query_lower.end(), query_lower.begin(), ::tolower);

    vector<Student> results;
    for (const auto& student : students) {
        string name_lower = student.name;
        string dept_lower = student.department;
        transform(name_lower.begin(), name_lower.end(), name_lower.begin(), ::tolower);
        transform(dept_lower.begin(), dept_lower.end(), dept_lower.begin(), ::tolower);
        if (name_lower.find(query_lower) != string::npos || dept_lower.find(query_lower) != string::npos) {
            results.push_back(student);
        }
    }

    if (results.empty()) {
        cout << "No matching records found!" << endl;
    } else {
        display_all_students(results);
    }
}

void sort_students(vector<Student>& students) {
    string choice;
    cout << "Sort by (1) GPA or (2) Roll Number? Enter 1 or 2: ";
    cin >> choice;

    if (choice == "1") {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.gpa > b.gpa; // Descending order for GPA
        });
    } else if (choice == "2") {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.roll_number < b.roll_number; // Ascending order for roll number
        });
    } else {
        cout << "Invalid choice!" << endl;
        return;
    }
    cout << "Records sorted successfully!" << endl;
    display_all_students(students);
}