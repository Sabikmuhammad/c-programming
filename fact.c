#include<stdio.h>

// Function to calculate factorial of a number
int factorial(int n) {
   if(n==1||n==0) return 1; //base cases
   return n*factorial(n-1);
}

int main() {
    int num;
  //  scanf("%d",&num);
    printf("Factorial is %d ", factorial(5));
    return 0;
}