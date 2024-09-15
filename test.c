#include <stdio.h>

int main(void) {
    int temp;

    printf("Input temperature: ");
    scanf("%d", &temp);

    switch (temp)
    {
    case 40:
        printf("Turn on the AC");
        break;
    case 10:
        printf("Turn on the heater");
        break;
    default:
        printf("invalid temp");
    }
    
};