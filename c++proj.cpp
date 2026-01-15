#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 50;
const int SUBJECTS = 5;

struct Student {
    int id;
    string name;
    float grades[SUBJECTS];
    float average;
};


float calculateAverage(float grades[]) {
    float sum = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        sum += grades[i];
    }
    return sum / SUBJECTS;
}


void addStudent(Student students[], int &count) {
    if (count >= MAX_STUDENTS) {
        cout << "Student list is full!\n";
        return;
    }

    cout << "Enter student ID: ";
    cin >> students[count].id;

    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, students[count].name);

    cout << "Enter grades for " << SUBJECTS << " subjects:\n";
    for (int i = 0; i < SUBJECTS; i++) {
        cout << "Grade " << i + 1 << ": ";
        cin >> students[count].grades[i];
    }

    students[count].average = calculateAverage(students[count].grades);
    count++;

    cout << "Student added successfully.\n";
}


void displayStudents(Student students[], int count) {
    if (count == 0) {
        cout << "No students to display.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "\nStudent ID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nAverage: " << students[i].average << endl;
    }
}


void searchStudent(Student students[], int count) {
    int searchId;
    cout << "Enter student ID to search: ";
    cin >> searchId;

    for (int i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            cout << "\nStudent Found!";
            cout << "\nName: " << students[i].name;
            cout << "\nAverage: " << students[i].average << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}


void showMenu() {
    cout << "\n--- Student Academic Tracker ---\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students, studentCount);
            break;
        case 2:
            displayStudents(students, studentCount);
            break;
        case 3:
            searchStudent(students, studentCount);
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

