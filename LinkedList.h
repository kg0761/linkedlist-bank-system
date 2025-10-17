#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Account.h"

class LinkedList {
private:
    struct Node {
        Account account;
        Node* next;
        Node(const Account& newAccount) : account(newAccount), next(nullptr) {}
    };

    Node* head; // Pointer to the first node in the linked list

public:
    LinkedList();              // Constructor
    ~LinkedList();             // Destructor

    void addAccount(const Account& newAccount);        // Add an account to the linked list
    Account* findAccount(int accountNumber);           // Find an account by account number
    void printAccounts() const;                        // Print all accounts in the list
    bool deposit(int accountNumber, double amount, const std::string& accountName);  // Deposit money into an account
    bool withdraw(int accountNumber, double amount, const std::string& accountName); // Withdraw money from an account
};

#endif
