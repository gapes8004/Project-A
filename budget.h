#ifndef BUDGET_H
#define BUDGET_H

#include "common.h"

#define MAX_BUDGETS 50

void addBudget(void);
double calculateRemainingBudget(double allocated, double expenditure);
int isBudgetExceeded(int index);
void displayBudgets(void);
void listExceededBudgets(void);
void budgetMenu(void);

int getBudgetCount(void);
double calculateTotalAllocated(void);
double calculateTotalExpenditure(void);

#endif
