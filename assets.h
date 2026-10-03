#ifndef ASSETS_H
#define ASSETS_H

#include "common.h"

#define MAX_ASSETS 50

typedef struct {
    int    assetId;
    char   name[NAME_LEN];
    char   type[NAME_LEN];
    double purchaseValue;
    char   department[DEPT_LEN];
    char   condition[COND_LEN];
} Asset;

void addAsset(Asset assets[], int *count);

void displayAssets(const Asset assets[], int count);

void searchAsset(const Asset assets[], int count);

void assetMenu(Asset assets[], int *count);

#endif