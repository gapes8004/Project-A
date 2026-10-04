#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "utils.h"

void employeeReport(void)
{
    int count = getEmployeeCount();
    double total = 0.0;
    double highest;
    double lowest;
    double gross;

    printf("\n==== EMPLOYEE REPORT ====\n");

    if (count == 0)
    {
        printf("No employees recorded.\n");
        return;
    }

    highest = getEmployeeGrossSalary(0);
    lowest = highest;

    for (int i = 0; i < count; i++)
    {
        gross = getEmployeeGrossSalary(i);
        total += gross;

        if (gross > highest)
        {
            highest = gross;
        }
        if (gross < lowest)
        {
            lowest = gross;
        }
    }

    printf("Total Employees: %d\n", count);
    printf("Average Salary:  N$%.2f\n", total / count);
    printf("Highest Salary:  N$%.2f\n", highest);
    printf("Lowest Salary:   N$%.2f\n", lowest);
}

void budgetReport(void)
{
    double totalAllocated;
    double totalExpenditure;

    printf("\n==== BUDGET REPORT ====\n");

    if (getBudgetCount() == 0)
    {
        printf("No budget records.\n");
        return;
    }

    totalAllocated = calculateTotalAllocated();
    totalExpenditure = calculateTotalExpenditure();

    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure:      N$%.2f\n", totalExpenditure);
    printf("Remaining Budget:       N$%.2f\n",
           calculateRemainingBudget(totalAllocated, totalExpenditure));

    listExceededBudgets();
}

void supplierReport(void)
{
    printf("\n==== SUPPLIER REPORT ====\n");
    printf("Total Suppliers Registered: %d\n", getSupplierCount());
    displaySuppliers();
}

void assetReport(void)
{
    printf("\n==== ASSET REPORT ====\n");
    printf("Total Assets Registered: %d\n", getAssetCount());
    printf("Total Asset Value: N$%.2f\n", calculateTotalAssetValue());
    displayAssets();
}

void reportsMenu(void)
{
    int choice;

    do
    {
        printf("\n---- REPORTS ----\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        choice = getValidatedInt("Enter your choice: ", 1, 5);

        switch (choice)
        {
            case 1:
                employeeReport();
                break;
            case 2:
                budgetReport();
                break;
            case 3:
                supplierReport();
                break;
            case 4:
                assetReport();
                break;
            case 5:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
}
