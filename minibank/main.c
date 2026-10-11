#include <stdio.h>

#include "account.h"
#include "transaction.h"
#include "report.h"
#include "config.h"
#include "logger.h"

int main(void)
{
    Account alice;
    Account bob;

    account_init(&alice, 101, "Alice", INITIAL_BALANCE);
    account_init(&bob, 102, "Bob", 500.0);

    printf("\n=== %s ===\n", BANK_NAME);

    account_deposit(&alice, 250.0);
    account_withdraw(&alice, 100.0);

    transaction_transfer(&alice, &bob, 200.0);

    report_account(&alice);
    report_account(&bob);

    report_projected_balance(&alice, 5.0, 3);

    return 0;
}