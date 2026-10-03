
#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "common.h"

#define MAX_EMPLOYEES 100

typedef struct {
    int    employeeId;
    char   name[NAME_LEN];
    char   department[DEPT_LEN];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
} Employee;

void addEmployee(Employee employees[], int *count);

void displayEmployees(const Employee employees[], int count);

void searchEmployee(const Employee employees[], int count);

double calculateGrossSalary(const Employee *emp);

void employeeMenu(Employee employees[], int *count);

#endif 
