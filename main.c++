#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;

    void input() {
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void display() {
        cout << id << " | " << name << " | " << age << endl;
    }
};

void addStudent();
void viewStudents();

int main() {
    int choice;
    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n2. View Students\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: exit(0);
            default: cout << "Invalid choice!\n";
        }
    }
}

void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);
    s.input();
    file << s.id << " " << s.name << " " << s.age << endl;
    file.close();
    cout << "Student added successfully!\n";
}

void viewStudents() {
    Student s;
    ifstream file("students.txt");
    cout << "\nID | Name | Age\n";
    while (file >> s.id >> s.name >> s.age) {
        s.display();
    }
    file.close();
}
