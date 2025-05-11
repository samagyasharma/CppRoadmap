#include <iostream>
using namespace std;

// Function declarations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    char operation;
    double num1, num2;
    char again;

    do {
        // Display calculator menu
        cout << "\nSimple Calculator\n";
        cout << "----------------\n";
        cout << "Choose an operation:\n";
        cout << "+ : Addition\n";
        cout << "- : Subtraction\n";
        cout << "* : Multiplication\n";
        cout << "/ : Division\n";
        cout << "Enter your choice: ";
        cin >> operation;

        // Get the two numbers
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        // Perform calculation based on operation
        switch (operation) {
            case '+':
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case '-':
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case '*':
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case '/':
                // Check for division by zero
                if (num2 == 0) {
                    cout << "Error: Cannot divide by zero!" << endl;
                } else {
                    cout << "Result: " << divide(num1, num2) << endl;
                }
                break;
            default:
                cout << "Error: Invalid operation!" << endl;
        }

        // Ask if user wants to calculate again
        cout << "\nDo you want to calculate again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "Thank you for using the calculator!" << endl;
    return 0;
}

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    return a / b;
} 