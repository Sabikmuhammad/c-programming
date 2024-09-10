#include<stdio.h>
int main()
{
    int day;
    printf("enter the day");
    scanf("%d",&day);
    switch (day)
    {
    case 1/* constant-expression */:
        /* code */
        printf("monday");
        break;
     case 2/* constant-expression */:
        /* code */
        printf("tuesday");
        break;
     case 3/* constant-expression */:
        /* code */
        printf("wednasday");
        break;
     case 4/* constant-expression */:
        /* code */
        printf("thursday");
        break;
     case 5/* constant-expression */:
        /* code */
        printf("friday");
        break;
     case 6/* constant-expression */:
        /* code */
        printf("saturday");
        break;
     case 7/* constant-expression */:
        /* code */
        printf("sunday");
        break;
    
    default:printf("enter the number between 1 to 7");
        break;
    }
}
