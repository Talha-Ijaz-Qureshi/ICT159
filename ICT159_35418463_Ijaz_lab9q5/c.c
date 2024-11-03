#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "h.h"

// Reads data from the file and stores it in dynamically allocated arrays
int readDataFromFile(const char *filename, char ***names, int **ages, float **wages, int *recordCount) {
    FILE *src = fopen(filename, "r");
    if (src == NULL) {
        perror("Failed to open input file.");
        return -1;
    }

    char tempName[NAME_SIZE];
    int tempAge;
    float tempWage;
    *recordCount = 0;

    // Loop to read each record
    while (fscanf(src, "%s %d %f\n", tempName, &tempAge, &tempWage) != EOF) {
        *names = realloc(*names, (*recordCount + 1) * sizeof(char *));
        *ages = realloc(*ages, (*recordCount + 1) * sizeof(int));
        *wages = realloc(*wages, (*recordCount + 1) * sizeof(float));

        if (*names == NULL || *ages == NULL || *wages == NULL) {
            perror("Memory allocation failed.");
            fclose(src);
            return -1;
        }

        (*names)[*recordCount] = malloc(NAME_SIZE * sizeof(char));
        if ((*names)[*recordCount] == NULL) {
            perror("Memory allocation failed.");
            fclose(src);
            return -1;
        }
        strncpy((*names)[*recordCount], tempName, NAME_SIZE);
        (*ages)[*recordCount] = tempAge;
        (*wages)[*recordCount] = tempWage;
        (*recordCount)++;
    }

    fclose(src);
    return 0;
}

void writeDataToFile(const char *filename, char **names, int *ages, float *wages, int recordCount) {
    FILE *dest = fopen(filename, "w");
    if (dest == NULL) {
        perror("Failed to open output file.");
        return;
    }

    for (int i = 0; i < recordCount; i++) {
        fprintf(dest, "%s,%d,%.2f\n", names[i], ages[i], wages[i]);
    }
    fclose(dest);
    printf("Data has been successfully written to %s.\n", filename);
}

void freeMemory(char **names, int *ages, float *wages, int recordCount) {
    for (int i = 0; i < recordCount; i++) {
        free(names[i]);
    }
    free(names);
    free(ages);
    free(wages);
}

void searchAndPrintRecord(char **names, int *ages, float *wages, int recordCount, const char *searchName) {
    for (int i = 0; i < recordCount; i++) {
        if (strcmp(names[i], searchName) == 0) {
            printf("Name: %s, Age: %d, Wage: %.2f\n", names[i], ages[i], wages[i]);
            return;
        }
    }
    printf("Name not found\n");
}
