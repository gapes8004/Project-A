
#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void employeeReport(const Employee employees[], int count);


void budgetReport(const Budget budgets[], int count);


void supplierReport(const Supplier suppliers[], int count);


void assetReport(const Asset assets[], int count);


void reportsMenu(Employee employees[], int employeeCount,
                  Budget budgets[], int budgetCount,
                  Supplier suppliers[], int supplierCount,
                  Asset assets[], int assetCount);

#endif 
