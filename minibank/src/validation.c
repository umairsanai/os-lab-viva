#include "validation.h"

int is_valid_amount(double amount)
{
    return amount > 0.0;
}

int is_valid_account_id(int id)
{
    return id > 0;
}