#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utils.h"

char budgetDepartments[MAX_BUDGETS][DEPT_LEN];
double allocatedBudgets[MAX_BUDGETS];
double expenditures[MAX_BUDGETS];
int budgetCount = 0;

void addBudget(void)
{
    char department[DEPT_LEN];

    if (budgetCount >= MAX_BUDGETS)
    {
        printf("\nError: Budget list is full (maximum %d).\n", MAX_BUDGETS);
        return;
    }

    getValidatedString("Enter Department Name: ", department, DEPT_LEN);

    for (int i = 0; i < budgetCount; i++)
    {
        if (strcmp(budgetDepartments[i], department) == 0)
        {
            printf("Error: A budget for department '%s' already exists.\n", department);
            return;
        }
    }

    strcpy(budgetDepartments[budgetCount], department);
    allocatedBudgets[budgetCount] = getValidatedDouble("Enter Allocated Budget (N$): ", 0.0);
    expenditures[budgetCount] = getValidatedDouble("Enter Expenditure (N$): ", 0.0);

    printf("\nBudget for '%s' added successfully. Status: ", budgetDepartments[budgetCount]);
    if (isBudgetExceeded(budgetCount))
    {
        printf("EXCEEDED BUDGET\n");
    }
    else
    {
        printf("WITHIN BUDGET\n");
    }

    budgetCount++;
}

double calculateRemainingBudget(double allocated, double expenditure)
{
    return allocated - expenditure;
}

int isBudgetExceeded(int index)
{
    if (expenditures[index] > allocatedBudgets[index])
    {
        return 1;
    }
    return 0;
}

void displayBudgets(void)
{
    if (budgetCount == 0)
    {
        printf("\nNo budget records yet.\n");
        return;
    }

    printf("\n%-20s %15s %15s %15s %18s\n",
           "Department", "Allocated", "Expenditure", "Remaining", "Status");
    printLine(87);

    for (int i = 0; i < budgetCount; i++)
    {
        printf("%-20s %15.2f %15.2f %15.2f ",
               budgetDepartments[i],
               allocatedBudgets[i],
               expenditures[i],
               calculateRemainingBudget(allocatedBudgets[i], expenditures[i]));

        if (isBudgetExceeded(i))
        {
            printf("%18s\n", "EXCEEDED BUDGET");
        }
        else
        {
            printf("%18s\n", "WITHIN BUDGET");
        }
    }
}

void listExceededBudgets(void)
{
    int anyExceeded = 0;

    printf("\n--- Departments Exceeding Budget ---\n");
    for (int i = 0; i < budgetCount; i++)
    {
        if (isBudgetExceeded(i))
        {
            printf("- %s (exceeded by N$%.2f)\n",
                   budgetDepartments[i],
                   expenditures[i] - allocatedBudgets[i]);
            anyExceeded = 1;
        }
    }

    if (!anyExceeded)
    {
        printf("No departments have exceeded their budget.\n");
    }
}

int getBudgetCount(void)
{
    return budgetCount;
}

double calculateTotalAllocated(void)
{
    double total = 0.0;

    for (int i = 0; i < budgetCount; i++)
    {
        total += allocatedBudgets[i];
    }
    return total;
}

double calculateTotalExpenditure(void)
{
    double total = 0.0;

    for (int i = 0; i < budgetCount; i++)
    {
        total += expenditures[i];
    }
    return total;
}

void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n---- BUDGET MANAGEMENT ----\n");
        printf("1. Add Department Budget\n");
        printf("2. Display All Budgets\n");
        printf("3. List Departments Exceeding Budget\n");
        printf("4. Back to Main Menu\n");
        choice = getValidatedInt("Enter your choice: ", 1, 4);

        switch (choice)
        {
            case 1:
                addBudget();
                break;
            case 2:
                displayBudgets();
                break;
            case 3:
                listExceededBudgets();
                break;
            case 4:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
}
