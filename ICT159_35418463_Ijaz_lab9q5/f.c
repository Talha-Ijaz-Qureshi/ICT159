#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "h.h"

int main(int argc, char *argv[]) {
    char **names = NULL;
    int *ages = NULL;
    float *wages = NULL;
    int recordCount = 0;

    if (argc == 2) {
        printf("The argument supplied is %s\n", argv[1]);

        // Read data from file
        if (readDataFromFile(argv[1], &names, &ages, &wages, &recordCount) == -1) {
            return -1;
        }

        // Write data to output file in CSV format
        writeDataToFile("output.csv", names, ages, wages, recordCount);

        // Search for a name entered by the user
        char searchName[NAME_SIZE];
        printf("Enter a name to search: ");
        scanf("%s", searchName);
        searchAndPrintRecord(names, ages, wages, recordCount, searchName);

        // Free dynamically allocated memory
        freeMemory(names, ages, wages, recordCount);

    } else if (argc > 2) {
        printf("Too many arguments supplied.\n");
    } else {
        printf("One argument expected.\n");
    }

    return 0;
}
