#ifndef BANK_H
#define BANK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// Forward declarations
typedef struct Bank Bank;
typedef struct Account Account;

struct Bank{
    int nAcc;               // Number of all accounts 
    double money;           // Amount of money
    double maxLoan;         // Maximum amount of money that can be loaned for each request
    double loanInterest;    // Interest given on loans
    double transferFeeRate; // Fee rate for transfers from different banks
    Account **accounts;      // array of pointers to all accounts
};

typedef struct Loan{
    bool active;        // Loan is active
    double amount;      // Amount of Loan
    double interest;    // interest * amount needs to be paid back
}Loan;

struct Account{
    int id;         // Account ID
    bool active;    // Used for closing of the account
    double balance; // Amount of money (won't go negative)
    Loan loan;      // Loan information
    Bank *bank;     // Pointer to bank
};

// Given the input parameters, the function allocates a Bank and returns a pointer to it.
// at the start there are no accounts thus accounts is NULL
//Given to students
Bank* CreateBank(double money, double maxLoan, double loanInterest, double transferFeeRate);

// The function force free all memory even if the accounts are not closed, to avoid memory leak.
// Given to students
Bank* ForceDestroyBank(Bank *bank);

//Prints information about the bank.
//Given to students
void ShowBank(Bank *bank);

//The function orders all accounts of a bank to pay their active loans. 
// Loans are paid one by one according to the order of accounts array. 
// If one account fails to pay the loan (account balance is not enough to pay the loan), 
//   the function returns false
bool CollectLoanPayments(Bank *bank);

// Given a pointer to a bank, returns a new account. 
// The accounts array grows by 1 each time a new account is created.
// the function creates the account's id (which is the number of accounts starting from 1), 
// have the balance of 0, be marked active and point to the bank that created it.
// The default Loan variables are false, 0.0, 1.0
Account* OpenAccount(Bank *bank);

// First pays an active loan the account has, if successful then closes the account.
// This closing is done by just marking the account inactive and setting it’s balance
// to zero. Returns true or false depending on success.
bool CloseAccount(Account *account);

// Prints information about the account.
// Given to students
void ShowAccount(Account *account);

// Deposits money to an account. You must check to see if the account is
// active first. Depositing money will only increase account’s balance. The money
// variable in Bank represents Bank’s own money that is used to give out loans.
void Deposit(double amount, Account *account);

// Withdraw does the opposite of deposit. However, make sure the account has
// enough balance to withdraw the amount (otherwise do not withdraw partial amount). 
// Withdraw returns a bool to indicate
// if the operation was successful or not.
bool Withdraw(double amount, Account *account);

// Request to take a loan of amount units. Firstly, check if the account is active
// and doesn’t have an active loan already. If the amount is less than the maximum
// loan to be given by the bank, increase the balance of the account by amount
// provided that there is also enough money in the bank (the money variable of
// the bank is the money it uses to lend out loans, and should be updated as well). Set the loan struct of the
// account so that it can be paid back by consulting this variable. Lastly, return
// true or false, depending on the success of the loan.
bool TakeLoan(double amount, Account *account);

// Pays an active loan from account balance. Firstly, check if the account is active
// and has an active loan. Then, check if there is enough balance to pay back the
// loan. The amount that should be paid is interest * amount. 
// Don't forget to update the bank money as well
// Return true or false, depending on the success of the transaction.
bool PayLoan(Account *account);

// Request to transfer some amount of money from one account to another. A fee
// has to be paid if the transfer is between different banks. This fee is equal to
// transferFeeRate * amount.
// Fee is paid to the sender’s bank by sender. This fee increases money of the bank.
// Receiver receives amount.
bool Transfer(double amount, Account *sender, Account *receiver);

#endif
