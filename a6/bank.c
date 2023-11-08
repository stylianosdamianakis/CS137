#include "bank.h"

Bank* CreateBank(double money, double maxLoan,
                 double loanInterest, double transferFeeRate) {
    // Allocate bank
    Bank *bank = malloc(sizeof(Bank));
    assert(bank);
    // No accounts yet
    bank->accounts = NULL;
    bank->nAcc = 0;
    // Assign inputs
    bank->money = money;
    bank->maxLoan = maxLoan;
    bank->loanInterest = loanInterest;
    bank->transferFeeRate = transferFeeRate;

    return bank;
}

Account* OpenAccount(Bank *bank) {
    struct Loan loan = {false, 0.0, 1.0};
    struct Account *acc = malloc(sizeof(Account));

    //bank configuration
    if (bank->accounts == NULL) {
        bank->accounts = malloc(sizeof(Account));
        bank->accounts[bank->nAcc] = acc;
    } else {
        bank->accounts = realloc(bank->accounts, bank->nAcc * sizeof(Account));
        bank->accounts[bank->nAcc] = acc;
    }
    bank->nAcc++;

    //account configuration
    acc->id = bank->nAcc;
    acc->loan = loan;
    acc->bank = bank;
    acc->active = true;
    acc->balance = 0.0;

    return acc;
}

void Deposit(double amount, Account *account) {
    if (account->active) account->balance += amount;
}

bool Withdraw(double amount, Account *account) {
    if (account->active && account->balance >= amount) {
        account->balance -= amount;
        return true;
    }
    return false;
}

bool TakeLoan(double amount, Account *account) {
    if (!account->active || account->loan.active || amount > account->bank->maxLoan ||
    amount > account->bank->money) return false;

    account->bank->money -= amount;
    account->balance += amount;
    account->loan.amount = amount;
    account->loan.interest = account->bank->loanInterest;
    account->loan.active = true;
    return true;
}

bool PayLoan(Account *account) {
    double toPay = account->loan.amount * account->loan.interest;
    if (!account->active || !account->loan.active) return true;
    if (account->balance < toPay) return false;

    account->balance -= toPay;
    account->bank->money += toPay;
    account->loan.amount = 0;
    account->loan.interest = 1.0;
    account->loan.active = false;
    return true;
}

bool Transfer(double amount, Account *sender, Account *receiver) {

    //create a transfer fee if applicable
    double transferFee = 0;
    if (sender->bank != receiver->bank) {
        transferFee = amount * sender->bank->transferFeeRate;
    }

    if (!sender->active || !receiver->active || sender->balance < amount + transferFee) return false;
    sender->balance -= amount + transferFee;
    sender->bank->money += transferFee;
    receiver->balance += amount;
    return true;
}

bool CollectLoanPayments(Bank *bank) {

    //can everyone pay the loan
    for (int i = 0; i < bank->nAcc; i++) {
        Account *account = bank->accounts[i];
        if (!account->active || !account->loan.active) continue;
        if (account->balance < account->loan.amount * account->loan.interest) return false;
    }

    //pay the loans
    for (int i = 0; i < bank->nAcc; i++) {
        PayLoan(bank->accounts[i]);
    }

    return true;
}

bool CloseAccount(Account *account) {

    if (!account->active) return true;
    if (account->loan.active && account->balance < account->loan.amount * account->loan.interest) return false;
    PayLoan(account);
    account->active = false;
    return true;
}

Bank* ForceDestroyBank(Bank *bank) {
    // Check if bank exists
    if (!bank)
        return NULL;
    // Just free the memory
    for (int i = 0; i < bank->nAcc; i++) {
        free(bank->accounts[i]);
    }
    free(bank->accounts);

    free(bank);
    bank = NULL;
    return NULL;
}

void ShowAccount(Account *account) {
    printf("Account #%d:\n", account->id);
    if (account->active) {
        printf("Balance: %.3f\n", account->balance);
        if (account->loan.active) {
            printf("Loaned %.3f with interest %f\n",
                   account->loan.amount, account->loan.interest);
        }
    } else {
        printf("Inactive account\n");
    }
}

void ShowBank(Bank *bank) {
    printf("BANK:\n");
    printf("Total money in bank: %.3f\n", bank->money);
    printf("Maximum loan offered: %.3f\n", bank->maxLoan);
    printf("Interest for loans: %f\n", bank->loanInterest);
    printf("Fee for a money transfer: %f\n", bank->transferFeeRate);
    //printf("----------------\n");
    for (int i = 0; i < bank->nAcc; i++) {
        ShowAccount(bank->accounts[i]);
        printf("----------------\n");
    }
}
