#include <stdio.h>
#include "coinsCalc.h"

int main() {
    int stop = 0, amount, ccy;
    int coins[4];

    do {
        ccy = ccySelect();
        do {
            amount = readAmount();
            if (validCheck(amount, ccy)) {
                calcCoins(amount, ccy, coins);
                break;
            }
        } while (1);
        displayCoins(coins, ccy);
        stop = proceedPrgm();
    } while (stop == 0);
    printf("Program Terminated.\n");
    return 0;
}
