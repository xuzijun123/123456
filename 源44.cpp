    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>
    using namespace std;

    struct Student {
        string name;
        int age;
        string id;
    };

    void addStudent(vector<Student>& students) {
        Student newStudent;
        cout << "Enter student name: ";
        cin >> newStudent.name;
        cout << "Enter student age: ";
        cin >> newStudent.age;
        cout << "Enter student ID: ";
        cin >> newStudent.id;
        students.push_back(newStudent);
        cout << "Student added successfully." << endl;
    }

    void displayStudents(const vector<Student>& students) {
        cout << "Student List:" << endl;
        for (const auto& student : students) {
            cout << "Name: " << student.name << ", Age: " << student.age << ", ID: " << student.id << endl;
        }
    }

    void searchStudent(const vector<Student>& students, const string& searchID) {
        auto it = find_if(students.begin(), students.end(), [&searchID](const Student& student) {
            return student.id == searchID;
            });
        if (it != students.end()) {
            cout << "Student found:" << endl;
            cout << "Name: " << it->name << ", Age: " << it->age << ", ID: " << it->id << endl;
        }
        else {
            cout << "Student with ID " << searchID << " not found." << endl;
        }
    }

    void deleteStudent(vector<Student>& students, const string& searchID) {
        auto it = find_if(students.begin(), students.end(), [&searchID](const Student& student) {
            return student.id == searchID;
            });
        if (it != students.end()) {
            students.erase(it);
            cout << "Student with ID " << searchID << " deleted successfully." << endl;
        }
        else {
            cout << "Student with ID " << searchID << " not found." << endl;
        }
    }

    bool compareByAge(const Student& student1, const Student& student2) {
        return student1.age < student2.age;
    }

    void sortStudentsByAge(vector<Student>& students) {
        sort(students.begin(), students.end(), compareByAge);
        cout << "Students sorted by age." << endl;
    }

    int main() {
        vector<Student> students;
        char choice;

        do {
            cout << "Student Information Management System" << endl;
            cout << "1. Add Student" << endl;
            cout << "2. Display Students" << endl;
            cout << "3. Search Student by ID" << endl;
            cout << "4. Delete Student by ID" << endl;
            cout << "5. Sort Students by Age" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case '1':
                addStudent(students);
                break;
            case '2':
                if (students.empty()) {
                    cout << "No students added yet." << endl;
                }
                else {
                    displayStudents(students);
                }
                break;
            case '3':
                if (students.empty()) {
                    cout << "No students added yet." << endl;
                }
                else {
                    string searchID;
                    cout << "Enter student ID to search: ";
                    cin >> searchID;
                    searchStudent(students, searchID);
                }
                break;
            case '4':
                if (students.empty()) {
                    cout << "No students added yet." << endl;
                }
                else {
                    string searchID;
                    cout << "Enter student ID to delete: ";
                    cin >> searchID;
                    deleteStudent(students, searchID);
                }
                break;
            case '5':
                if (students.empty()) {
                    cout << "No students added yet." << endl;
                }
                else {
                    sortStudentsByAge(students);
                }
                break;
            case '6':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
            }

        } while (choice != '6');

        return 0;
    }