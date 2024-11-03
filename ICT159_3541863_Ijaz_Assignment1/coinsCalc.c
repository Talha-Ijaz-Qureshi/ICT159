#include <stdio.h>
#include "coinsCalc.h"

int ccySelect() {
    int input, type;
    while (1) {
        printf("Please enter a corresponding number to select from the following currencies:\n");
        printf("1. US$\n");
        printf("2. AUS$\n");
        printf("3. Euro\n");
        type = scanf("%d", &input);
        while (getchar() != '\n');

        if (type == 1 && input > 0 && input < 4) {
            return input;
        } else {
            printf("Invalid selection. Please try again.\n \n");
        }
    }

    return 0;
}

int readAmount() {
    int amount;
    printf("\nEnter amount: ");
    scanf("%d", &amount);
    while (getchar() != '\n');
    return amount;
}

int validCheck(int input, int ccy) {
    if (ccy == 1 || ccy == 3) {
        if (input > 0 && input < 96) {
            printf("Amount: %d (***Note: Decimals values to be rounded to floor***) \n", input);
            return 1;
        } else {
            printf("Enter an integer value from 1-95 only.\n");
            return 0;
        }
    } else if (ccy == 2) {
        if (input % 5 == 0 && input > 0 && input < 96) {
            printf("Amount: %d\n", input);
            return 1;
        } else {
            printf("Value must be a multiple of 5 between 1-95 only.\n");
            return 0;
        }
    }

    return 0;
}

void calcCoins(int input, int ccy, int coinCount[]) {
    int ccyCents[3][4] = {{50, 25, 10, 1}, {50, 20, 10, 5}, {20, 10, 5, 1}};
    int i;

    for (i = 0; i < 4; i++) {
        coinCount[i] = input / ccyCents[ccy-1][i];
        input = input % ccyCents[ccy-1][i];
    }
}

void displayCoins(int coinCount[], int ccy) {
    int ccyCents[3][4] = {{50, 25, 10, 1}, {50, 20, 10, 5}, {20, 10, 5, 1}};
    int i;
    printf("\n");
    for (i = 0; i < 4; i++) {
        if (coinCount[i] != 0) {
            printf("%d x %d cent coin(s)\n", coinCount[i], ccyCents[ccy-1][i]);
        }
    }
}


int proceedPrgm() {
    int input;

    printf("\nWould you like to continue/exit the program?\n");
    printf("Enter 1 to continue or 2 to exit\n");

    while(1) {
        scanf("%d", &input);
        while (getchar() != '\n');

        if (input == 1) {
            return 0;
        } else if (input == 2) {
            return 1;
        } else {
            printf("Invalid input. Enter 1 to continue or 2 to exit.\n");
        }
    }
    return 0;
}
