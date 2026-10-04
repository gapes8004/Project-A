#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"
#include "utils.h"

void displayMainMenu(void);

int main(void)
{
    int choice;

    printf("\n======================================================\n");
    printf("\n Welcome to the Municipal Financial Management System \n");
    printf("\n======================================================\n");

    do
    {
        displayMainMenu();
        choice = getValidatedInt("Enter your choice: ", 1, 6);

        switch (choice)
        {
            case 1:
                employeeMenu();
                break;
            case 2:
                budgetMenu();
                break;
            case 3:
                supplierMenu();
                break;
            case 4:
                assetMenu();
                break;
            case 5:
                reportsMenu();
                break;
            case 6:
                printf("\nThank you for visiting the Municipal Financial Management System.\n");
                printf("                  Please do visit us again                         \n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMainMenu(void)
{
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}
