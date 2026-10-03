
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

#define LINE_BUFFER_SIZE 256


static void stripNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}


static int isBlank(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i])) {
            return 0;
        }
    }
    return 1;
}

int getValidatedInt(const char *prompt, int min, int max) {
    char line[LINE_BUFFER_SIZE];
    int value = 0;
    int valid = 0;

    do {
        printf("%s", prompt);

        if (fgets(line, sizeof(line), stdin) == NULL) {

            continue;
        }
        stripNewline(line);

        char extra;

        int itemsScanned = sscanf(line, "%d %c", &value, &extra);

        if (itemsScanned == 1) {
            if (value >= min && value <= max) {
                valid = 1;
            } else {
                printf("Error: Please enter a number between %d and %d.\n", min, max);
            }
        } else {
            printf("Error: Please enter a valid whole number.\n");
        }
    } while (!valid);

    return value;
}
    double getValidatedDouble(const char *prompt, double min) {
    char line[LINE_BUFFER_SIZE];
    double value = 0.0;
    int valid = 0;

    do {
        printf("%s", prompt);

        if (fgets(line, sizeof(line), stdin) == NULL) {
            continue;
        }
        stripNewline(line);

        char extra;
        int itemsScanned = sscanf(line, "%lf %c", &value, &extra);

        if (itemsScanned == 1) {
            if (value >= min) {
                valid = 1;
            } else {
                printf("Error: Value cannot be less than %.2f.\n", min);
            }
        } else {
            printf("Error: Please enter a valid number.\n");
        }
    } while (!valid);

    return value;
}

void getValidatedString(const char *prompt, char *buffer, int size) {
    int valid = 0;

    do {
        printf("%s", prompt);

        if (fgets(buffer, size, stdin) == NULL) {
            continue;
        }
        stripNewline(buffer);

        if (strlen(buffer) == 0 || isBlank(buffer)) {
            printf("Error: Input cannot be empty.\n");
        } else {
            valid = 1;
        }
    } while (!valid);
}
