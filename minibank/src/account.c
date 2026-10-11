#include <stdio.h>
#include <string.h>

#include "account.h"
#include "validation.h"
#include "logger.h"

void account_init(Account *account, int id,
                  const char *owner, double balance)
{
    account->id = id;

    snprintf(account->owner, sizeof(account->owner),
             "%s", owner);

    account->balance = balance;
    log_info("Account initialized");
}

int account_deposit(Account *account, double amount)
{
    if (!is_valid_amount(amount)) {
        log_error("Invalid deposit amount");
        return 0;
    }

    account->balance += amount;
    log_info("Deposit successful");
    return 1;
}

int account_withdraw(Account *account, double amount)
{
    if (!is_valid_amount(amount) ||
        amount > account->balance) {
        log_error("Withdrawal rejected");
        return 0;
    }

    account->balance -= amount;
    log_info("Withdrawal successful");
    return 1;
}