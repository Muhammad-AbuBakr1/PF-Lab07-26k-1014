#include <stdio.h>

int main(void) {
    int stock[] = {25, 12, 8, 40, 5, 18, 3, 22};
    int size = (int)(sizeof(stock) / sizeof(stock[0]));
    int i;

    printf("End-of-day stock levels:\n");
    for (i = 0; i < size; i++) {
        printf("Item %d: %d units\n", i + 1, stock[i]);
        if (stock[i] < 10)
            printf("Item %d is LOW on stock - reorder required\n", i + 1);
    }

    int itemNumber, quantitySold;

    do {
        printf("\nEnter item number (1-%d, 0 to stop): ", size);
        if (scanf("%d", &itemNumber) != 1) { while (getchar() != '\n'); continue; }

        if (itemNumber == 0) break;

        if (itemNumber < 1 || itemNumber > size) {
            printf("Invalid item number. Please try again.\n");
            continue;
        }

        printf("Enter quantity sold: ");
        if (scanf("%d", &quantitySold) != 1) { while (getchar() != '\n'); continue; }

        if (quantitySold < 0) {
            printf("Invalid quantity. Sale cancelled.\n");
            continue;
        }

        int index = itemNumber - 1;
        if (quantitySold > stock[index]) {
            printf("Error: not enough stock. Sale cancelled.\n");
        } else {
            stock[index] -= quantitySold;
            printf("Sale recorded. Item %d now has %d units.\n",
                   itemNumber, stock[index]);
        }
    } while (itemNumber != 0);

    printf("\nFinal stock levels:\n");
    int totalUnits = 0, leastIndex = 0;
    for (i = 0; i < size; i++) {
        printf("Item %d: %d units\n", i + 1, stock[i]);
        totalUnits += stock[i];
        if (stock[i] < stock[leastIndex]) leastIndex = i;
    }
    printf("\nTotal units remaining: %d\n", totalUnits);
    printf("Item with least stock: Item %d (%d units)\n",
           leastIndex + 1, stock[leastIndex]);

    return 0;
}
