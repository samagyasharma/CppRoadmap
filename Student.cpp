#include <iostream>
#include <string>
using namespace std;

// Student class definition
class Student {
    // Private members - can only be accessed within the class
    private:
        string name;        // Student's name
        int rollNumber;     // Student's roll number
        float marks;        // Student's marks

    // Public members - can be accessed from outside the class
    public:
        // Default constructor - initializes with default values
        Student() {
            name = "Unknown";
            rollNumber = 0;
            marks = 0.0;
        }

        // Parameterized constructor - initializes with provided values
        Student(string n, int roll, float m) {
            name = n;
            rollNumber = roll;
            marks = m;
        }

        // Function to print student details
        void printDetails() {
            cout << "\nStudent Details:" << endl;
            cout << "Name: " << name << endl;
            cout << "Roll Number: " << rollNumber << endl;
            cout << "Marks: " << marks << endl;
        }
};

int main() {
    // Create a student object using default constructor
    Student student1;
    cout << "Student 1 (Default Constructor):";
    student1.printDetails();

    // Create a student object using parameterized constructor
    Student student2("John Doe", 101, 85.5);
    cout << "\nStudent 2 (Parameterized Constructor):";
    student2.printDetails();

    return 0;
} 