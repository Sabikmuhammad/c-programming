#include<stdio.h>
int add(int a,int b);
int multiply(int a,int b){
    return a*b;
}
int main()
{
    int sum=add(5,3);
    printf("sum:%d",sum);
    printf("multiply:%d",multiply(6,7));
    printf("multiply:%d",multiply(6,7));
    return 0;
}
int add (int a,int b){
    return a+b;
}