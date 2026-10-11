#include <stdio.h>

#include "report.h"
#include "finance.h"
#include "config.h"
#include "logger.h"

void report_account(const Account *account)
{
    printf("\n--- %s Account Report ---\n", BANK_NAME);
    printf("Account ID: %d\n", account->id);
    printf("Owner: %s\n", account->owner);
    printf("Balance: %.2f\n", account->balance);
}

void report_projected_balance(const Account *account,
                              double annual_rate, int years)
{
    double projected = calculate_interest(
        account->balance, annual_rate, years);

    printf("Projected balance after %d years: %.2f\n",
           years, projected);

    log_info("Projection generated");
}