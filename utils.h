#ifndef UTILS_H
#define UTILS_H

int getValidatedInt(char prompt[], int min, int max);
double getValidatedDouble(char prompt[], double min);
void getValidatedString(char prompt[], char buffer[], int size);
void printLine(int length);

#endif
