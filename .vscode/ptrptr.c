#include <stdio.h>

int main() {
    int var = 10;
    int *ptr = &var;
    int **pptr = &ptr;

    printf("Value of var: %d\n", var);
    printf("Value pointed to by ptr: %d\n", *ptr);
    printf("Value pointed to by pptr: %d\n", **pptr);

    return 0;
}