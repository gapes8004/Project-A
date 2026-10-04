#include <stdio.h>
#include <string.h>
#include "utils.h"

#define LINE_BUFFER_SIZE 256

int readLine(char line[], int size);
int isBlank(char text[]);

int readLine(char line[], int size)
{
    char extra[LINE_BUFFER_SIZE];
    int fitted = 1;
    int length;

    line[0] = '\0';
    fgets(line, size, stdin);
    length = strlen(line);

    if (line[strcspn(line, "\n")] == '\n')
    {
        line[strcspn(line, "\n")] = '\0';
    }
    else if (length == size - 1)
    {
        fitted = 0;
        do
        {
            extra[0] = '\0';
            fgets(extra, sizeof(extra), stdin);
        } while (strlen(extra) > 0 && extra[strcspn(extra, "\n")] != '\n');
    }

    return fitted;
}

int isBlank(char text[])
{
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (text[i] != ' ' && text[i] != '\t')
        {
            return 0;
        }
    }
    return 1;
}

int getValidatedInt(char prompt[], int min, int max)
{
    char line[LINE_BUFFER_SIZE];
    int value;
    int valid;
    int length;

    do
    {
        valid = 1;
        value = 0;

        printf("%s", prompt);
        readLine(line, LINE_BUFFER_SIZE);
        length = strlen(line);

        if (line[0] == '-')
        {
            printf("Error: Negative values are not accepted.\n");
            valid = 0;
        }
        else if (length == 0 || length > 9)
        {
            printf("Error: Please enter a valid whole number.\n");
            valid = 0;
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                if (line[i] < '0' || line[i] > '9')
                {
                    valid = 0;
                    break;
                }
                value = value * 10 + (line[i] - '0');
            }

            if (!valid)
            {
                printf("Error: Please enter a valid whole number.\n");
            }
            else if (value < min || value > max)
            {
                printf("Error: Please enter a number between %d and %d.\n", min, max);
                valid = 0;
            }
        }
    } while (!valid);

    return value;
}

double getValidatedDouble(char prompt[], double min)
{
    char line[LINE_BUFFER_SIZE];
    double value;
    double place;
    int valid;
    int length;
    int dotCount;
    int decimals;

    do
    {
        valid = 1;
        value = 0.0;
        place = 0.1;
        dotCount = 0;
        decimals = 0;

        printf("%s", prompt);
        readLine(line, LINE_BUFFER_SIZE);
        length = strlen(line);

        if (line[0] == '-')
        {
            printf("Error: Negative values are not accepted.\n");
            valid = 0;
        }
        else if (length == 0 || length > 15)
        {
            printf("Error: Please enter a valid number.\n");
            valid = 0;
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                if (line[i] == '.')
                {
                    dotCount++;
                    if (dotCount > 1)
                    {
                        valid = 0;
                        break;
                    }
                }
                else if (line[i] >= '0' && line[i] <= '9')
                {
                    if (dotCount == 0)
                    {
                        value = value * 10 + (line[i] - '0');
                    }
                    else
                    {
                        value += (line[i] - '0') * place;
                        place /= 10;
                        decimals++;
                    }
                }
                else
                {
                    valid = 0;
                    break;
                }
            }

            if (!valid || (dotCount == 1 && length == 1))
            {
                printf("Error: Please enter a valid number.\n");
                valid = 0;
            }
            else if (decimals > 2)
            {
                printf("Error: Use at most 2 decimal places.\n");
                valid = 0;
            }
            else if (value < min)
            {
                printf("Error: Value cannot be less than %.2f.\n", min);
                valid = 0;
            }
        }
    } while (!valid);

    return value;
}

void getValidatedString(char prompt[], char buffer[], int size)
{
    char line[LINE_BUFFER_SIZE];
    int valid = 0;
    int fitted;
    int length;

    do
    {
        printf("%s", prompt);
        fitted = readLine(line, LINE_BUFFER_SIZE);
        length = strlen(line);

        if (fitted == 0 || length > size - 1)
        {
            printf("Error: Input is too long (maximum %d characters).\n", size - 1);
        }
        else if (isBlank(line))
        {
            printf("Error: Input cannot be empty.\n");
        }
        else
        {
            strcpy(buffer, line);
            valid = 1;
        }
    } while (!valid);
}

void printLine(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("-");
    }
    printf("\n");
}
