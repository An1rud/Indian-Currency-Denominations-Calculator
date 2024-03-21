#include <stdio.h>

void coinChange(int amount) {
    int denominations[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int numCoins[sizeof(denominations) / sizeof(denominations[0])];
    int i, count;

    for (i = 0; i < sizeof(denominations) / sizeof(denominations[0]); i++) {
        if (amount >= denominations[i]) {
            count = amount / denominations[i];
            numCoins[i] = count;
            amount -= count * denominations[i];
        } else {
            numCoins[i] = 0;
        }
    }

    printf("Indian Currency Denominations:\n");
    for (i = 0; i < sizeof(denominations) / sizeof(denominations[0]); i++) {
        if (numCoins[i] > 0) {
            printf("%d x Rs %d\n", numCoins[i], denominations[i]);
        }
    }
}

int main() {
    int amount;

    printf("Enter the amount in rupees: ");
    scanf("%d", &amount);

    coinChange(amount);

    return 0;
}
