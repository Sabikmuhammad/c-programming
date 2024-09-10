#include <stdio.h>
#include <stdlib.h>

int main() {
    // Using malloc()
    int* ptr1 = calloc(1,sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    *ptr1 = 10;
    printf("Value of ptr1: %d\n", *ptr1);

    // Using calloc()
    int* ptr2 = malloc( sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Value of ptr2: %d\n", *ptr2); // prints 0

    free(ptr1);
    free(ptr2);
    return 0;
}