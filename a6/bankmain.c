#include "bank.h"
#include <stdio.h>
/*

int main(void) {

    Bank *b0 = CreateBank(1000, 100, 1.0001, 0.0001);
    Bank *b1 = CreateBank(2000, 300, 1.0001, 0.0001);
    Account *a0 = OpenAccount(b0);
    Deposit(200, a0);
    TakeLoan(100, a0);
    ShowBank(b0);


    printf("creating b0\n");
    Bank *b0 = CreateBank(1000, 100, 1.0001, 0.0001);
    assert(b0);
    printf("creating b1\n");
    Bank *b1 = CreateBank(2000, 300, 1.0001, 0.0001);
    assert(b1);
    printf("adding a0 to b0\n");
    Account *a0 = OpenAccount(b0);
    assert(a0);
    printf("adding a1 to b1\n");
    Account *a1 = OpenAccount(b1);
    assert(a1);
    printf("adding a2 to b1\n");
    Account *a2 = OpenAccount(b1);
    assert(a2);
    printf("deposit 200 in a0\n");
    Deposit(200, a0);
    ShowAccount(a0);
    printf("loan 100 for a0\n");
    TakeLoan(100, a0);
    ShowAccount(a0);
    printf("deposit 500 in a1\n");
    Deposit(500, a1);
    ShowAccount(a1);
    printf("deposit 400 in a2\n");
    Deposit(400, a2);
    ShowAccount(a2);

// Deposit
    printf("deposit 300 in a0\n");
    Deposit(300, a0);
    printf("deposit 300 in a1\n");
    Deposit(300, a1);
    printf("deposit 100 in a2\n");
    Deposit(100, a2);

    ShowBank(b0);
    printf("*********\n");
    ShowBank(b1);
    // Withdraw
    printf("withdraw 200 from a0\n");
    Withdraw(200, a0);

    ShowBank(b0);
    printf("*********\n");
    ShowBank(b1);
    // Take Loan
    printf("100 loan to a0\n");
    TakeLoan(100, a0);

    // Transfer
    printf("100 transfer from a1 to a0\n");
    Transfer(100, a1, a0);  // No fee same bank
    printf("50 transfer from a1 to a2\n");
    Transfer(50, a1, a2);   // Fee applied - different banks

    ShowBank(b0);
    printf("*********\n");
    ShowBank(b1);
    // Pay Loan
    printf("colect loan payment b0\n");
    CollectLoanPayments(b0);

    ShowBank(b0);
    printf("*********\n");
    ShowBank(b1);

    Withdraw(5000, a1);
    ShowAccount(a1);
    printf("close a1\n");

    CloseAccount(a1);
    ShowBank(b0);
    printf("*********\n");
    ShowBank(b1);
    printf("the end\n");

    // Force Destroy
    ForceDestroyBank(b0);
    ForceDestroyBank(b1);
    return 0;
}
*/