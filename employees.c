
#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utils.h"

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: Employee list is full (maximum %d). Cannot add more.\n", MAX_EMPLOYEES);
        return;
    }

    Employee newEmp;

    newEmp.employeeId = getValidatedInt("Enter Employee ID: ", 1, 999999);

    for (int i = 0; i < *count; i++) {
        if (employees[i].employeeId == newEmp.employeeId) {
            printf("Error: Employee ID %d already exists.\n", newEmp.employeeId);
            return;
        }
    }

    getValidatedString("Enter Employee Name: ", newEmp.name, NAME_LEN);
    getValidatedString("Enter Department: ", newEmp.department, DEPT_LEN);
    newEmp.basicSalary         = getValidatedDouble("Enter Basic Salary (N$): ", 0.0);
    newEmp.housingAllowance    = getValidatedDouble("Enter Housing Allowance (N$): ", 0.0);
    newEmp.transportAllowance  = getValidatedDouble("Enter Transport Allowance (N$): ", 0.0);

    employees[*count] = newEmp;
    (*count)++;

    printf("\nEmployee '%s' added successfully. (Gross Salary: N$%.2f)\n",
           newEmp.name, calculateGrossSalary(&newEmp));
}

void displayEmployees(const Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employees recorded yet.\n");
        return;
    }

    printf("\n%-6s %-20s %-15s %12s %12s %12s %12s\n",
           "ID", "Name", "Department", "Basic", "Housing", "Transport", "Gross");
    for (int i = 0; i < 90; i++) putchar('-');
    putchar('\n');

    for (int i = 0; i < count; i++) {
        double gross = calculateGrossSalary(&employees[i]);
        printf("%-6d %-20s %-15s %12.2f %12.2f %12.2f %12.2f\n",
               employees[i].employeeId,
               employees[i].name,
               employees[i].department,
               employees[i].basicSalary,
               employees[i].housingAllowance,
               employees[i].transportAllowance,
               gross);
    }
}

void searchEmployee(const Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employees recorded yet.\n");
        return;
    }

    int searchChoice = getValidatedInt("Search by (1) Employee ID or (2) Name: ", 1, 2);
    int found = 0;

    if (searchChoice == 1) {
        int id = getValidatedInt("Enter Employee ID to search: ", 1, 999999);
        for (int i = 0; i < count; i++) {
            if (employees[i].employeeId == id) {
                found = 1;
                printf("\n--- Employee Found ---\n");
                printf("ID:         %d\n", employees[i].employeeId);
                printf("Name:       %s\n", employees[i].name);
                printf("Department: %s\n", employees[i].department);
                printf("Gross Salary: N$%.2f\n", calculateGrossSalary(&employees[i]));
                break;
            }
        }
    } else {
        char name[NAME_LEN];
        getValidatedString("Enter Employee Name to search: ", name, NAME_LEN);
        for (int i = 0; i < count; i++) {
            if (strcmp(employees[i].name, name) == 0) {
                found = 1;
                printf("\n--- Employee Found ---\n");
                printf("ID:         %d\n", employees[i].employeeId);
                printf("Name:       %s\n", employees[i].name);
                printf("Department: %s\n", employees[i].department);
                printf("Gross Salary: N$%.2f\n", calculateGrossSalary(&employees[i]));
                break;
            }
        }
    }

    if (!found) {
        printf("\nNo employee matched your search.\n");
    }
}

double calculateGrossSalary(const Employee *emp) {
    return emp->basicSalary + emp->housingAllowance + emp->transportAllowance;
}

void employeeMenu(Employee employees[], int *count) {
    int choice;

    do {
        printf("\n---- EMPLOYEE MANAGEMENT ----\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Back to Main Menu\n");
        choice = getValidatedInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1:
                addEmployee(employees, count);
                break;
            case 2:
                displayEmployees(employees, *count);
                break;
            case 3:
                searchEmployee(employees, *count);
                break;
            case 4:
                printf("Returning to main menu...\n");
                break;
        }
    } while (choice != 4);
}
