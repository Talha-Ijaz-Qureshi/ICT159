#include <stdio.h>

int main() {
    int nterm, f_zero = 0, f_one = 1, nvalue, typeCheck;

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
    

    printf("Fibonacci sequence till F(%d):\n", nterm);
    printf("%d ", f_zero);

    if (nterm > 0) {
        printf("%d ", f_one);
    }

    for (int i = 2; i <= nterm; i++) {
        nvalue = f_zero + f_one;
        printf("%d ", nvalue);
        f_zero = f_one;
        f_one = nvalue;
    }
    getchar();
    return 0;
}

