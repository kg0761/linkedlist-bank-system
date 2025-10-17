#include "LinkedList.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor initializes an empty linked list
LinkedList::LinkedList() : head(nullptr) {}

// Destructor cleans up the linked list
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Adds a new account to the linked list
void LinkedList::addAccount(const Account& newAccount) {
    Node* newNode = new Node(newAccount);
    newNode->next = head;
    head = newNode;
}

// Finds an account by account number
Account* LinkedList::findAccount(int accountNumber) {
    Node* current = head;
    while (current != nullptr) {
        if (current->account.getAccountNumber() == accountNumber) {
            return &current->account;
        }
        current = current->next;
    }
    return nullptr; // Return nullptr if the account was not found
}

// Prints all accounts in the linked list
void LinkedList::printAccounts() const {
    Node* current = head;
    while (current != nullptr) {
        current->account.printAccountDetails();
        current = current->next;
    }
}

// Deposits money into an account
bool LinkedList::deposit(int accountNumber, double amount, const std::string& accountName) {
    Account* account = findAccount(accountNumber);
    if (account != nullptr) {
        account->deposit(amount);
        cout << "Deposit successful! New balance: $" << fixed << setprecision(2) << account->getBalance() << endl;
        return true;
    }
    return false;
}

// Withdraws money from an account
bool LinkedList::withdraw(int accountNumber, double amount, const std::string& accountName) {
    Account* account = findAccount(accountNumber);
    if (account != nullptr) {
        if (account->getBalance() >= amount) {
            account->withdraw(amount);
            cout << "Withdrawal successful! New balance: $" << fixed << setprecision(2) << account->getBalance() << endl;
            return true;
        } else {
            cout << "Insufficient balance for withdrawal!" << endl;
        }
    }
    return false;
}
