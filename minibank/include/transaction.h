#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "account.h"

int transaction_transfer(Account *from, Account *to,
                         double amount);

#endif