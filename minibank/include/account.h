#ifndef ACCOUNT_H
#define ACCOUNT_H

#define ACCOUNT_NAME_SIZE 64

typedef struct {
    int id;
    char owner[ACCOUNT_NAME_SIZE];
    double balance;
} Account;

void account_init(Account *account, int id,
                  const char *owner, double balance);

int account_deposit(Account *account, double amount);
int account_withdraw(Account *account, double amount);

#endif