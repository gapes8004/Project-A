

#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utils.h"

void addBudget(Budget budgets[], int *count) {
    if (*count >= MAX_BUDGETS) {
        printf("\nError: Budget list is full (maximum %d).\n", MAX_BUDGETS);
        return;
    }

    Budget newBudget;
    getValidatedString("Enter Department Name: ", newBudget.department, DEPT_LEN);

  
    for (int i = 0; i < *count; i++) {
        if (strcmp(budgets[i].department, newBudget.department) == 0) {
            printf("Error: A budget for department '%s' already exists.\n", newBudget.department);
            return;
        }
    }

    newBudget.allocatedBudget = getValidatedDouble("Enter Allocated Budget (N$): ", 0.0);
    newBudget.expenditure     = getValidatedDouble("Enter Expenditure (N$): ", 0.0);

    budgets[*count] = newBudget;
    (*count)++;

    printf("\nBudget for '%s' added successfully. Status: %s\n",
           newBudget.department, budgetStatus(&newBudget));
}

double calculateRemainingBudget(const Budget *b) {
    return b->allocatedBudget - b->expenditure;
}

const char *budgetStatus(const Budget *b) {
    if (b->expenditure > b->allocatedBudget) {
        return "EXCEEDED BUDGET";
    }
    return "WITHIN BUDGET";
}

void displayBudgets(const Budget budgets[], int count) {
    if (count == 0) {
        printf("\nNo budget records yet.\n");
        return;
    }

    printf("\n%-20s %15s %15s %15s %18s\n",
           "Department", "Allocated", "Expenditure", "Remaining", "Status");
    for (int i = 0; i < 85; i++) putchar('-');
    putchar('\n');

    for (int i = 0; i < count; i++) {
        printf("%-20s %15.2f %15.2f %15.2f %18s\n",
               budgets[i].department,
               budgets[i].allocatedBudget,
               budgets[i].expenditure,
               calculateRemainingBudget(&budgets[i]),
               budgetStatus(&budgets[i]));
    }
}

void listExceededBudgets(const Budget budgets[], int count) {
    int anyExceeded = 0;

    printf("\n--- Departments Exceeding Budget ---\n");
    for (int i = 0; i < count; i++) {
        if (budgets[i].expenditure > budgets[i].allocatedBudget) {
            printf("- %s (exceeded by N$%.2f)\n",
                   budgets[i].department,
                   budgets[i].expenditure - budgets[i].allocatedBudget);
            anyExceeded = 1;
        }
    }

    if (!anyExceeded) {
        printf("No departments have exceeded their budget.\n");
    }
}

void budgetMenu(Budget budgets[], int *count) {
    int choice;

    do {
        printf("\n---- BUDGET MANAGEMENT ----\n");
        printf("1. Add Department Budget\n");
        printf("2. Display All Budgets\n");
        printf("3. List Departments Exceeding Budget\n");
        printf("4. Back to Main Menu\n");
        choice = getValidatedInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1:
                addBudget(budgets, count);
                break;
            case 2:
                displayBudgets(budgets, *count);
                break;
            case 3:
                listExceededBudgets(budgets, *count);
                break;
            case 4:
                printf("Returning to main menu...\n");
                break;
        }
    } while (choice != 4);
}
