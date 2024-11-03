#include <stdio.h>

int main() {
    int nterm, typeCheck;
    unsigned long long int f_zero = 0, f_one = 1, nvalue = 0;

    printf("Enter the nth-term for F(n): ");
    typeCheck = scanf("%d", &nterm);
    getchar();

    if (nterm < 0 && typeCheck == 1) {
        printf("Enter a positive integer only\n");
        while (getchar() != '\n');
        return 1;
    }
    else if (typeCheck == 0)
    {
        printf("Enter a positive integer only\n");
        while (getchar() != '\n');
        getchar();
        return 1;
    }
    
    printf("%d ", f_zero);

    if (nterm > 0) {
        printf("%d ", f_one);
        nvalue = f_one;
    }

    for (int i = 2; i <= nterm; i++) {
        nvalue = f_zero + f_one;
        printf("%llu ", nvalue);
        f_zero = f_one;
        f_one = nvalue;
    }

    printf("\nValue of Fibonacci series at F(%d): %llu \n", nterm, nvalue);
    getchar();
    return 0;
}

