#include <stdio.h>
#include<string.h>
int main() {
    FILE* fp = fopen("example.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    char* data = "Hello, World!";
    fwrite(data, sizeof(char), strlen(data), fp);
    fclose(fp);
    return 0;
}