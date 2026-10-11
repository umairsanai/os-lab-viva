#include <pthread.h>

#include "transaction.h"
#include "account.h"
#include "finance.h"
#include "logger.h"

static pthread_mutex_t transaction_lock =
    PTHREAD_MUTEX_INITIALIZER;

int transaction_transfer(Account *from, Account *to,
                         double amount)
{
    int success = 0;

    if (from == to || amount <= 0.0)
        return 0;

    pthread_mutex_lock(&transaction_lock);

    double fee = calculate_transaction_fee(amount);

    if (from->balance >= amount + fee) {
        from->balance -= amount + fee;
        to->balance += amount;
        log_info("Transfer completed");
        success = 1;
    } else {
        log_error("Insufficient funds for transfer and fee");
    }

    pthread_mutex_unlock(&transaction_lock);

    return success;
}