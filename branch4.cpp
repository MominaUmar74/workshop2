#include <iostream>
#include <vector>
#include <string>

// Function declarations (to be linked with other modules)
void save_students(const vector<Student>& students);
vector<Student> load_students();
void add_student(vector<Student>& students);
void update_student(vector<Student>& students);
void delete_student(vector<Student>& students);
void display_all_students(const vector<Student>& students);
void display_student_by_roll(const vector<Student>& students);
void search_students(const vector<Student>& students);
void sort_students(vector<Student>& students);

int main() {
    vector<Student> students = load_students();
    string choice;

    while (true) {
        cout << "\n=== Student Record Management System ===" << endl;
        cout << "1. Add New Student" << endl;
        cout << "2. View All Students" << endl;
        cout << "3. View Student by Roll Number" << endl;
        cout << "4. Update Student Record" << endl;
        cout << "5. Delete Student Record" << endl;
        cout << "6. Search Students" << endl;
        cout << "7. Sort Students" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == "0") {
            save_students(students);
            cout << "Data saved. Exiting..." << endl;
            break;
        } else if (choice == "1") {
            add_student(students);
        } else if (choice == "2") {
            display_all_students(students);
        } else if (choice == "3") {
            display_student_by_roll(students);
        } else if (choice == "4") {
            update_student(students);
        } else if (choice == "5") {
            delete_student(students);
        } else if (choice == "6") {
            search_students(students);
        } else if (choice == "7") {
            sort_students(students);
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}