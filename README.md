Municipal Financial Management System

Collaborators

Iipinge Gabriel 224020455

Kandume Jona 220106657

Mutilifa Lovisa 220049386

Project Overview

This project is a Municipal Financial Management System (MFMS) designed for a Namibian municipality. The system is a menu-driven command-line application built using arrays, strings and functions in ANSI C, offering the following features:

Employee Management: Adds, displays and searches employee records, and calculates gross salary from basic pay plus allowances.

Budget Management: Records departmental budgets and expenditure, calculates remaining balance, and flags departments that have exceeded their allocation.

Supplier Management: Adds, displays and searches municipal supplier records including contact details and location.

Asset Management: Maintains a register of municipal assets such as vehicles, computers, buildings and equipment, with search and display functionality.

Reports: Generates summary reports for employees, budgets, suppliers and assets, including totals, averages and departments over budget.

Repository Structure

The project is divided into the following modules:

main.c - Entry point of the program. Owns the data arrays and displays the main menu.

common.h - Shared constants used across all modules.

utils.h / utils.c - Shared input validation functions for integers, decimals and strings.

employees.h / employees.c - Employee Management module.

budget.h / budget.c - Budget Management module.

suppliers.h / suppliers.c - Supplier Management module.

assets.h / assets.c - Asset Management module.

reports.h / reports.c - Reports module, which reads data from the other four modules.

Makefile - Build script used to compile the project.

Each team member contributed to a different module of the project, including algorithm design, coding, testing and documentation. Further details about individual contributions can be found in the project's Individual Contribution Record.
