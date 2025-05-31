# Bank Account Management System

A C++ implementation of a bank account management system that demonstrates object-oriented programming concepts, particularly encapsulation and data protection.

## Features

- Account management with validation
- Support for different account types (Savings/Checking)
- Interest calculation
- Account activation/deactivation
- Input validation for all operations
- Protected data access through getters and setters

## Class Structure

The `BankAccount` class includes:

### Private Members
- Account number
- Account holder name
- Account type
- Balance
- Interest rate
- Account status

### Public Methods
- Constructor with validation
- Deposit and withdrawal operations
- Getter methods for all private members
- Setter methods with validation
- Account activation/deactivation
- Interest calculation

## Usage

```cpp
// Create a new account
BankAccount account("ACC123456", "John Doe", "Savings", 1000.0, 0.02);

// Deposit money
account.deposit(500.0);

// Withdraw money
account.withdraw(200.0);

// Get account information
cout << "Balance: " << account.getBalance() << endl;
cout << "Interest: " << account.calculateInterest() << endl;
```

## Compilation

Compile the program using a C++ compiler:

```bash
g++ BankAccount.cpp -o bank_account
```

## Requirements

- C++ compiler with C++11 support or later
- Standard C++ libraries 