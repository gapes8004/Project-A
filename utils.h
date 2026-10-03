
#ifndef UTILS_H
#define UTILS_H


int getValidatedInt(const char *prompt, int min, int max);


double getValidatedDouble(const char *prompt, double min);


void getValidatedString(const char *prompt, char *buffer, int size);

#endif 
