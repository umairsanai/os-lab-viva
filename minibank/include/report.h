#ifndef REPORT_H
#define REPORT_H

#include "account.h"

void report_account(const Account *account);
void report_projected_balance(const Account *account,
                              double annual_rate, int years);

#endif