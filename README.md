Municipal Financial Management System (MFMS)

Group members

1. Kandume Jona 220106657

2. Abigail Angula 224020633

3. Mutilifa Lovisa 220049386

4. Victor Shikomba 201022303

5. Gisela Shigwedha 222130520

6. Iipinge Gabriel 224020455

7. Kapembe Petrus 224009818


Project Description

The MFMS is a menu-driven C application that manages employees, budgets, suppliers and assets for a
municipality, with built-in reporting and input validation.

System Features

● Employee Management — add, display, and search employees (by ID or name), and automatically
calculate gross salary (basic salary + housing allowance + transport allowance).

● Budget Management — record each department's allocated budget and expenditure, calculate the
remaining balance, flag departments as WITHIN BUDGET or EXCEEDED BUDGET, and list every
department that has overspent.

● Supplier Management — add, display, and search municipal suppliers (ID, name, email, phone, town).

● Asset Management — maintain a basic register of municipal assets (vehicles, computers, buildings,
equipment, furniture), with search and display functionality.

● Reports — generate an employee report (total/average/highest/lowest salary), a budget report (totals and
departments over budget), a supplier report, and an asset report (count and total value).

● Input Validation — negative salaries, negative budgets, empty names, non-numeric input, and invalid menu
choices are all rejected and re-prompted rather than crashing the program.

Repository Structure

MFMS/

main.c Entry point: owns the data arrays, shows the
 main menu, dispatches to each module

common.h -Shared constants used across all modules

utils.h / utils.c -Shared input-validation functions

employees.h / employees.c -Employee Management module

budget.h / budget.c -Budget Management module

suppliers.h / suppliers.c -Supplier Management module

assets.h / assets.c Asset -Management module

reports.h / reports.c -Reports module

Makefile -Build script

.gitignore

README.md

Compilation Instructions

1: Using the Makefile as it was recommended "make"

This compiles every source file and produces an executable called mfms (or mfms.exe on Window )

2: Manual compilation with GCC

gcc -Wall -Wextra -std=c99 -g -o mfms main.c employees.c budget.c \
 suppliers.c assets.c reports.c utils.c

Cleaning build files

make clean

How to Run the System

.\mfms.exe

Each option opens that module's own submenu. Select option 6 from the main menu to exit the program

Individual Responsibilities

Jona  -Employee Management >employees.h, employees.c

Lovisa -Budget Management >budget.h, budget.c

Gisela -Supplier Management >suppliers.h, suppliers.c

Abigail -Asset Management >assets.h, assets.c

Victor -Reports >reports.h, reports.c

 Gabriel -Functions, integration & validation >main.c, utils.h, utils.c

Petrus -Testing, documentation & Git coordination >README.md, overall testing
