#include <stdio.h>

int main(void) {
    char input[30]   = {0};
    char cleaned[30] = {0};

    printf("Enter phone number: ");

    if (scanf("%29[^\n]", input) != 1) {
        printf("No input read.\n");
        return 1;
    }

    int j = 0, i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            cleaned[j] = input[i];
            j++;
        }
    }
    cleaned[j] = '\0';           

    printf("Original input : %s\n", input);
    printf("Cleaned number : %s\n", cleaned);
    printf("Digit count    : %d\n", j);

    if (j == 11)
        printf("Valid local number\n");
    else
        printf("Invalid length - please re-enter\n");

    return 0;
}
