#include <math.h>
#include "finance.h"

double calculate_interest(double principal,
                          double annual_rate, int years)
{
    return principal * pow(1.0 + annual_rate / 100.0, years);
}

double calculate_transaction_fee(double amount)
{
    return amount * 0.01;
}