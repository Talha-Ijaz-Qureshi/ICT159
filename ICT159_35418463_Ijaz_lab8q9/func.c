#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int getNvalue() {
    float n;
    while (1) {
        printf("Enter an integer for the maximum length of the string (1-100): ");
        if (scanf("%f", &n) == 1 && n > 0 && n <= 100 && n == (int)n) {
            while (getchar() != '\n');
            return (int)n;
        } else {
            printf("Invalid input. Please enter an integer between 1 and 100.\n");
            while (getchar() != '\n');
        }
    }
}

int readStr(int n, char *inputArr) {
    while (1) {
        printf("Enter a string with a maximum of %d letters: ", n);
        for(int j = 0; j < n; j++){
            inputArr[j] = 0;
        }
        int i = 0;
        char c;
        while ((c = getchar()) != '\n' && i < n) {
            inputArr[i++] = c; 
        }
        inputArr[i] = '\0';
        if (c != '\n') {
            printf("String must be %d or under character(s) long.\n", n);
            while (getchar() != '\n');
            continue;
        }
        if (i == 0) {
            printf("Input cannot be empty. Please try again.\n");
            while (getchar() != '\n');
            continue;
        }
        return 1;
    }
    return 0;
}




int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int vowelCount(int n, char *inputArr) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isVowel(inputArr[i])) {
            count++;
        }
    }
    return count;
}

char* returnVowels(char *inputArr, int n, int vowelN) {
    int j = 0;
    char *vowelArr = (char*)malloc((vowelN + 1) * sizeof(char));

    if (vowelArr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        if (isVowel(inputArr[i])) {
            vowelArr[j] = inputArr[i];
            j++;
        }
    }
    vowelArr[j] = '\0';
    return vowelArr;
}

void displayVowelsInfo(int vowelN, char *vowelArr) {
    char vowels[] = "aeiou";
    int vowelCount[5] = {0, 0, 0, 0, 0};
    int vowelIx[5] = {-1, -1, -1, -1, -1};

    for (int i = 0; i < vowelN; i++) {
        char c = vowelArr[i];
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
        for (int j = 0; j < 5; j++) {
            if (c == vowels[j]) {
                vowelCount[j]++;
                if (vowelIx[j] == -1) {
                    vowelIx[j] = i;
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        if (vowelCount[i] > 0) {
            printf("The vowel '%c' appeared %d time(s), first at index %d.\n", vowels[i], vowelCount[i], vowelIx[i]);
        } else {
            printf("The vowel '%c' does not appear in the string.\n", vowels[i]);
        }
    }
}

void printVowels(char *vowelArr) {
    printf("Vowels found from string: '%s'\n", vowelArr);
}
