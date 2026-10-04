# Municipal Financial Management System (MFMS) – Project A

**Course:** PAP521S – Programming in Practice
**Development Environment:** Visual Studio Code + GCC
**Version Control:** Git & GitHub

## Group Members

| No. | Name | Student Number |
|-----|------|----------------|
| 1 | Kandume Jona | 220106657 |
| 2 | Abigail Angula | 224020633 |
| 3 | Mutilifa Lovisa | 220049386 |
| 4 | Victor Shikomba | 201022303 |
| 5 | Gisela Shigwedha | 222130520 |
| 6 | Iipinge Gabriel | 224020455 |
| 7 | Kapembe Petrus | 224009818 |

## Project Description

The MFMS is a menu-driven C application that manages employees, budgets, suppliers
and assets for a municipality, with built-in reports and input validation. It is the
foundation version of the system (Project A) and will be extended in Project B.

The program is divided into modules. Each module keeps its own records in
parallel arrays, where the same index refers to the same record in every array. For
example, `employeeIds[2]`, `employeeNames[2]` and `basicSalaries[2]` all belong to the
third employee. Records are kept in memory while the program is running.

## System Features

- **Employee Management:** add, display and search employees (by ID or by name). The
  gross salary is calculated automatically as basic salary + housing allowance +
  transport allowance.
- **Budget Management:** record each department's allocated budget and expenditure,
  calculate the remaining budget, show each department as WITHIN BUDGET or EXCEEDED
  BUDGET, and list every department that has overspent.
- **Supplier Management:** add, display and search municipal suppliers (ID, name,
  email, telephone number and town).
- **Asset Management:** a register of municipal assets (ID, name, type, purchase value,
  department and condition) with display and search (by ID or by name).
- **Reports:**
  - Employee report: total employees, and average, highest and lowest salary.
  - Budget report: total allocated budget, total expenditure, remaining budget and departments over budget.
  - Supplier report: number of suppliers and the supplier list.
  - Asset report: number of assets, total asset value and the asset register.
- **Input Validation:** the following are rejected with an error message, and the user
  is asked again:
  - invalid menu choices;
  - letters in numbers;
  - negative amounts;
  - empty names;
  - text that is too long;
  - amounts with more than 2 decimal places;
  - duplicate IDs and duplicate department budgets.

## Repository Structure

| File | Purpose |
|------|---------|
| `main.c` | Entry point: shows the main menu and calls each module's menu |
| `common.h` | Shared constants (string sizes) used by all modules |
| `utils.h` / `utils.c` | Shared input-validation functions |
| `employees.h` / `employees.c` | Employee Management module |
| `budget.h` / `budget.c` | Budget Management module |
| `suppliers.h` / `suppliers.c` | Supplier Management module |
| `assets.h` / `assets.c` | Asset Management module |
| `reports.h` / `reports.c` | Reports module |
| `.gitignore` | Stops build files (`.o`, `mfms.exe`) from being committed |
| `README.md` | This file |

Every header file uses an include guard (`#ifndef` / `#define` / `#endif`).

## Compilation Instructions

Open a terminal in the project folder.

**Option 1 – compile each file separately, then link (Week 9):**

```
gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c suppliers.c
gcc -std=c99 -Wall -Wextra -pedantic -c assets.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
gcc -std=c99 -Wall -Wextra -pedantic -c utils.c
gcc main.o employees.o budget.o suppliers.o assets.o reports.o utils.o -o mfms
```

**Option 2 – compile and link in one command:**

```
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c suppliers.c assets.c reports.c utils.c -o mfms
```

The program compiles with no errors or warnings.

## How to Run the System

- **Windows (Command Prompt):** `mfms.exe`
- **Windows (PowerShell / VS Code terminal):** `.\mfms.exe`
- **Linux / macOS:** `./mfms`

Choose an option by typing its number and pressing Enter. Each option opens that
module's own submenu, which has a "Back to Main Menu" option. Select option 6 from the
main menu to exit the program.

## Individual Responsibilities

| Member | Responsibility | Files |
|--------|----------------|-------|
| Kandume Jona | Employee Management | `employees.h`, `employees.c` |
| Mutilifa Lovisa | Budget Management | `budget.h`, `budget.c` |
| Gisela Shigwedha | Supplier Management | `suppliers.h`, `suppliers.c` |
| Abigail Angula | Asset Management | `assets.h`, `assets.c` |
| Victor Shikomba | Reports | `reports.h`, `reports.c` |
| Iipinge Gabriel | Functions, integration, validation and Git coordination | `main.c`, `utils.h`, `utils.c`, `common.h` |
| Kapembe Petrus  | Testing and documentation| `README.md`, overall testing |
