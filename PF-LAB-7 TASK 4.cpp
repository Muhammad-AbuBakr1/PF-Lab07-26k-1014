#include <stdio.h>

int main(void) {
    char name[20] = {0};         

    printf("Enter display name: ");

    if (scanf("%19[A-Za-z]", name) != 1) {
        printf("No valid alphabetic name entered.\n");
        return 1;
    }

    int count = 0, i;
    for (i = 0; name[i] != '\0'; i++) {
        printf("Character at index %d: %c\n", i, name[i]);
        count++;
    }
    printf("Total characters stored: %d\n", count);

    if (name[0] >= 'a' && name[0] <= 'z')
        name[0] = name[0] - ('a' - 'A');  

    printf("Final name: %s\n", name);
    return 0;
}
