 #include<stdio.h>
#include<string.h>
int main()
{
    int len=0;
    char str[]="hello";
    while (str[len]!= '\0')
    {
      len++;
    }
    
    printf("length=%d",len);
    return 0;
}
  