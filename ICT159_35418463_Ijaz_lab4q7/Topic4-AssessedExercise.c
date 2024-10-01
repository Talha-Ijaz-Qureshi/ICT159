#include <stdio.h>


int main(void) {
    int speed, overSpeed, typeCheck;
    char *fine = NULL;

    printf("Enter your speed: ");
    typeCheck = scanf("%d", &speed);
    getchar();

    if ((speed < 0) && (typeCheck == 1)) {
        printf("Input valid positive number\n");
    }
    else if ((typeCheck == 0)) {
        printf("Input valid positive number\n");   
        while (getchar() != '\n');
    }

    else if (speed <= 60) {
        printf("Not Speeding");
    } 

    else {
        overSpeed = speed - 60;

        if (overSpeed <= 5) {
            fine = "Warning";

        } 

        else if (overSpeed > 5 && overSpeed <= 10) {
            fine = "$80";
        } 

        else if (overSpeed > 10 && overSpeed <= 20) {
            fine = "$150";
        } 

        else {
            fine = "$500";
        }
        printf("Speeding & Penalty Status: %s", fine);
    }
    getchar();
    return(0);
}
