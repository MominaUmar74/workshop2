#include <iostream>
#include <vector>
#include <string>

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

// Add, Update, Delete Functions
void add_student(vector<Student>& students) {
    string name, roll_number, department, contact;
    double gpa;

    cout << "Enter student name: ";
    cin.ignore(1, '\n');
    getline(cin, name);
    cout << "Enter roll number: ";
    getline(cin, roll_number);

    // Validate unique roll number
    for (const auto& student : students) {
        if (student.roll_number == roll_number) {
            cout << "Error: Roll number already exists!" << endl;
            return;
        }
    }

    cout << "Enter department: ";
    getline(cin, department);
    cout << "Enter GPA (0.0-4.0): ";
    string gpa_input;
    getline(cin, gpa_input);
    try {
        gpa = stod(gpa_input);
        if (gpa < 0.0 || gpa > 4.0) {
            cout << "Error: GPA must be between 0.0 and 4.0!" << endl;
            return;
        }
    } catch (...) {
        cout << "Error: Invalid GPA format!" << endl;
        return;
    }
    cout << "Enter contact info: ";
    getline(cin, contact);

    students.emplace_back(name, roll_number, department, gpa, contact);
    cout << "Student record added successfully!" << endl;
}

void update_student(vector<Student>& students) {
    string roll_number;
    cout << "Enter roll number to update: ";
    cin.ignore(1, '\n');
    getline(cin, roll_number);

    for (auto& student : students) {
        if (student.roll_number == roll_number) {
            cout << "Leave blank to keep current value." << endl;
            string input;

            cout << "Enter new name (" << student.name << "): ";
            getline(cin, input);
            if (!input.empty()) student.name = input;

            cout << "Enter new department (" << student.department << "): ";
            getline(cin, input);
            if (!input.empty()) student.department = input;

            cout << "Enter new GPA (" << fixed << setprecision(2) << student.gpa << "): ";
            getline(cin, input);
            if (!input.empty()) {
                try {
                    double new_gpa = stod(input);
                    if (new_gpa < 0.0 || new_gpa > 4.0) {
                        cout << "Error: GPA must be between 0.0 and 4.0!" << endl;
                        return;
                    }
                    student.gpa = new_gpa;
                } catch (...) {
                    cout << "Error: Invalid GPA format!" << endl;
                    return;
                }
            }

            cout << "Enter new contact (" << student.contact << "): ";
            getline(cin, input);
            if (!input.empty()) student.contact = input;

            cout << "Student record updated successfully!" << endl;
            return;
        }
    }
    cout << "Error: Student not found!" << endl;
}

void delete_student(vector<Student>& students) {
    string roll_number;
    cout << "Enter roll number to delete: ";
    cin.ignore(1, '\n');
    getline(cin, roll_number);

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->roll_number == roll_number) {
            students.erase(it);
            cout << "Student record deleted successfully!" << endl;
            return;
        }
    }
    cout << "Error: Student not found!" << endl;
}