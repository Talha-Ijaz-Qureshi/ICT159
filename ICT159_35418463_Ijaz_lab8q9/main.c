#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
    int n = getNvalue();
    char inputArr[101];

    readStr(n, inputArr);
    int numVowels = vowelCount(n, inputArr);
    if (numVowels == 0) {
        printf("No vowels found in the string.\n");
        return 0;
    }
    char *vowelArr = returnVowels(inputArr, n, numVowels);
    printVowels(vowelArr);
    displayVowelsInfo(numVowels, vowelArr);
    free(vowelArr);
    getchar();
    return 0;
}
