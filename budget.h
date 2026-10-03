

#ifndef BUDGET_H
#define BUDGET_H

#include "common.h"

#define MAX_BUDGETS 50

typedef struct {
    char   department[DEPT_LEN];
    double allocatedBudget;
    double expenditure;
} Budget;


void addBudget(Budget budgets[], int *count);

double calculateRemainingBudget(const Budget *b);

const char *budgetStatus(const Budget *b);

void displayBudgets(const Budget budgets[], int count);

void listExceededBudgets(const Budget budgets[], int count);

void budgetMenu(Budget budgets[], int *count);

#endif 
