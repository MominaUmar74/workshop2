#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

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

// File Handling Functions
void save_students(const vector<Student>& students) {
    ofstream file("students.txt");
    if (!file) {
        cout << "Error: Unable to open file for writing!" << endl;
        return;
    }
    for (const auto& student : students) {
        file << student.name << "|" << student.roll_number << "|" << student.department << "|"
             << fixed << setprecision(2) << student.gpa << "|" << student.contact << "\n";
    }
    file.close();
}

vector<Student> load_students() {
    vector<Student> students;
    ifstream file("students.txt");
    if (!file) {
        cout << "No existing data file found. Starting fresh." << endl;
        return students;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, roll_number, department, contact, gpa_str;
        getline(ss, name, '|');
        getline(ss, roll_number, '|');
        getline(ss, department, '|');
        getline(ss, gpa_str, '|');
        getline(ss, contact, '|');
        try {
            double gpa = stod(gpa_str);
            students.emplace_back(name, roll_number, department, gpa, contact);
        } catch (...) {
            cout << "Error reading record: " << line << endl;
        }
    }
    file.close();
    return students;
}
