#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utils.h"

void addAsset(Asset assets[], int *count) {
    if (*count >= MAX_ASSETS) {
        printf("\nError: Asset list is full (maximum %d).\n", MAX_ASSETS);
        return;
    }

    Asset newAsset;
    newAsset.assetId = getValidatedInt("Enter Asset ID: ", 1, 999999);

    for (int i = 0; i < *count; i++) {
        if (assets[i].assetId == newAsset.assetId) {
            printf("Error: Asset ID %d already exists.\n", newAsset.assetId);
            return;
        }
    }

    getValidatedString("Enter Asset Name: ", newAsset.name, NAME_LEN);
    getValidatedString("Enter Asset Type (Vehicle/Computer/Building/Equipment/Furniture): ",
                        newAsset.type, NAME_LEN);
    newAsset.purchaseValue = getValidatedDouble("Enter Purchase Value (N$): ", 0.0);
    getValidatedString("Enter Department: ", newAsset.department, DEPT_LEN);
    getValidatedString("Enter Condition (New/Good/Fair/Poor): ", newAsset.condition, COND_LEN);

    assets[*count] = newAsset;
    (*count)++;

    printf("\nAsset '%s' added successfully.\n", newAsset.name);
}

void displayAssets(const Asset assets[], int count) {
    if (count == 0) {
        printf("\nNo assets recorded yet.\n");
        return;
    }

    printf("\n%-6s %-18s %-13s %14s %-15s %-10s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");
    for (int i = 0; i < 85; i++) putchar('-');
    putchar('\n');

    for (int i = 0; i < count; i++) {
        printf("%-6d %-18s %-13s %14.2f %-15s %-10s\n",
               assets[i].assetId,
               assets[i].name,
               assets[i].type,
               assets[i].purchaseValue,
               assets[i].department,
               assets[i].condition);
    }
}

void searchAsset(const Asset assets[], int count) {
    if (count == 0) {
        printf("\nNo assets recorded yet.\n");
        return;
    }

    int searchChoice = getValidatedInt("Search by (1) Asset ID or (2) Name: ", 1, 2);
    int found = 0;

    if (searchChoice == 1) {
        int id = getValidatedInt("Enter Asset ID to search: ", 1, 999999);
        for (int i = 0; i < count; i++) {
            if (assets[i].assetId == id) {
                found = 1;
                printf("\n--- Asset Found ---\n");
                printf("ID:         %d\n", assets[i].assetId);
                printf("Name:       %s\n", assets[i].name);
                printf("Type:       %s\n", assets[i].type);
                printf("Value:      N$%.2f\n", assets[i].purchaseValue);
                printf("Department: %s\n", assets[i].department);
                printf("Condition:  %s\n", assets[i].condition);
                break;
            }
        }
    } else {
        char name[NAME_LEN];
        getValidatedString("Enter Asset Name to search: ", name, NAME_LEN);
        for (int i = 0; i < count; i++) {
            if (strcmp(assets[i].name, name) == 0) {
                found = 1;
                printf("\n--- Asset Found ---\n");
                printf("ID:         %d\n", assets[i].assetId);
                printf("Name:       %s\n", assets[i].name);
                printf("Type:       %s\n", assets[i].type);
                printf("Value:      N$%.2f\n", assets[i].purchaseValue);
                printf("Department: %s\n", assets[i].department);
                printf("Condition:  %s\n", assets[i].condition);
                break;
            }
        }
    }

    if (!found) {
        printf("\nNo asset matched your search.\n");
    }
}

void assetMenu(Asset assets[], int *count) {
    int choice;

    do {
        printf("\n---- ASSET MANAGEMENT ----\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back to Main Menu\n");
        choice = getValidatedInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1:
                addAsset(assets, count);
                break;
            case 2:
                displayAssets(assets, *count);
                break;
            case 3:
                searchAsset(assets, *count);
                break;
            case 4:
                printf("Returning to main menu...\n");
                break;
        }
    } while (choice != 4);
}