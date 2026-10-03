
#include <stdio.h>
#include "reports.h"
#include "utils.h"

void employeeReport(const Employee employees[], int count) {
    printf("\n==== EMPLOYEE REPORT ====\n");

    if (count == 0) {
        printf("No employees recorded.\n");
        return;
    }

    double total = 0.0;
    double highest = calculateGrossSalary(&employees[0]);
    double lowest  = highest;

    for (int i = 0; i < count; i++) {
        double gross = calculateGrossSalary(&employees[i]);
        total += gross;
        if (gross > highest) highest = gross;
        if (gross < lowest)  lowest  = gross;
    }

    printf("Total Employees: %d\n", count);
    printf("Average Salary:  N$%.2f\n", total / count);
    printf("Highest Salary:  N$%.2f\n", highest);
    printf("Lowest Salary:   N$%.2f\n", lowest);
}

void budgetReport(const Budget budgets[], int count) {
    printf("\n==== BUDGET REPORT ====\n");

    if (count == 0) {
        printf("No budget records.\n");
        return;
    }

    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;

    for (int i = 0; i < count; i++) {
        totalAllocated   += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
    }

    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure:      N$%.2f\n", totalExpenditure);
    printf("Remaining Budget:       N$%.2f\n", totalAllocated - totalExpenditure);

    listExceededBudgets(budgets, count);
}

void supplierReport(const Supplier suppliers[], int count) {
    printf("\n==== SUPPLIER REPORT ====\n");
    printf("Total Suppliers Registered: %d\n", count);
    displaySuppliers(suppliers, count);
}

void assetReport(const Asset assets[], int count) {
    printf("\n==== ASSET REPORT ====\n");
    printf("Total Assets Registered: %d\n", count);

    double totalValue = 0.0;
    for (int i = 0; i < count; i++) {
        totalValue += assets[i].purchaseValue;
    }
    printf("Total Asset Value: N$%.2f\n", totalValue);

    displayAssets(assets, count);
}

void reportsMenu(Employee employees[], int employeeCount,
                  Budget budgets[], int budgetCount,
                  Supplier suppliers[], int supplierCount,
                  Asset assets[], int assetCount) {
    int choice;

    do {
        printf("\n---- REPORTS ----\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        choice = getValidatedInt("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1:
                employeeReport(employees, employeeCount);
                break;
            case 2:
                budgetReport(budgets, budgetCount);
                break;
            case 3:
                supplierReport(suppliers, supplierCount);
                break;
            case 4:
                assetReport(assets, assetCount);
                break;
            case 5:
                printf("Returning to main menu...\n");
                break;
        }
    } while (choice != 5);
}
