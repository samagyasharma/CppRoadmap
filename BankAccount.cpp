#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    string accountType;  // "Savings" or "Checking"
    double balance;
    double interestRate;
    bool isActive;

public:
    // Constructor
    BankAccount(string accNum, string holderName, string type = "Savings", 
                double initialBalance = 0.0, double rate = 0.01) {
        accountNumber = accNum;
        accountHolderName = holderName;
        accountType = (type == "Savings" || type == "Checking") ? type : "Savings";
        interestRate = (rate >= 0) ? rate : 0.01;
        isActive = true;
        
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            cout << "Warning: Initial balance cannot be negative. Set to 0." << endl;
        }
    }

    // Deposit method with validation
    bool deposit(double amount) {
        if (!isActive) {
            cout << "Error: Account is inactive." << endl;
            return false;
        }
        if (amount <= 0) {
            cout << "Error: Deposit amount must be positive." << endl;
            return false;
        }
        balance += amount;
        cout << "Successfully deposited $" << amount << endl;
        return true;
    }

    // Withdraw method with validation
    bool withdraw(double amount) {
        if (!isActive) {
            cout << "Error: Account is inactive." << endl;
            return false;
        }
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive." << endl;
            return false;
        }
        if (amount > balance) {
            cout << "Error: Insufficient funds." << endl;
            return false;
        }
        balance -= amount;
        cout << "Successfully withdrew $" << amount << endl;
        return true;
    }

    // Get balance method
    double getBalance() const {
        return balance;
    }

    // Get account number method
    string getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    string getAccountType() const {
        return accountType;
    }

    double getInterestRate() const {
        return interestRate;
    }

    bool getAccountStatus() const {
        return isActive;
    }

    // Setters with validation
    bool setAccountHolderName(const string& newName) {
        if (newName.empty()) {
            cout << "Error: Name cannot be empty." << endl;
            return false;
        }
        accountHolderName = newName;
        return true;
    }

    bool setAccountType(const string& newType) {
        if (newType != "Savings" && newType != "Checking") {
            cout << "Error: Account type must be either 'Savings' or 'Checking'." << endl;
            return false;
        }
        accountType = newType;
        return true;
    }

    bool setInterestRate(double newRate) {
        if (newRate < 0) {
            cout << "Error: Interest rate cannot be negative." << endl;
            return false;
        }
        interestRate = newRate;
        return true;
    }

    void deactivateAccount() {
        isActive = false;
        cout << "Account has been deactivated." << endl;
    }

    void activateAccount() {
        isActive = true;
        cout << "Account has been activated." << endl;
    }

    // Calculate interest
    double calculateInterest() const {
        return balance * interestRate;
    }
};

// Example usage in main
int main() {
    // Create a new account
    BankAccount account("ACC123456", "John Doe", "Savings", 1000.0, 0.02);
    
    // Display account information
    cout << "Account Information:" << endl;
    cout << "Account Number: " << account.getAccountNumber() << endl;
    cout << "Account Holder: " << account.getAccountHolderName() << endl;
    cout << "Account Type: " << account.getAccountType() << endl;
    cout << "Interest Rate: " << (account.getInterestRate() * 100) << "%" << endl;
    cout << "Initial Balance: $" << account.getBalance() << endl;

    // Test deposit
    account.deposit(500.0);
    cout << "Balance after deposit: $" << account.getBalance() << endl;

    // Test interest calculation
    cout << "Interest earned: $" << account.calculateInterest() << endl;

    // Test account holder name change
    account.setAccountHolderName("John Smith");
    cout << "New account holder: " << account.getAccountHolderName() << endl;

    // Test invalid account type change
    account.setAccountType("Investment");

    // Test account deactivation
    account.deactivateAccount();
    account.deposit(100.0);  // Should fail due to inactive account

    // Reactivate account
    account.activateAccount();
    account.deposit(100.0);  // Should succeed

    return 0;
} 