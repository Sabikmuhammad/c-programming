#include <stdio.h>
#include<string.h>

int main() {
   int i,j=0,m,n;
   char str1[10]="hello";
   char str2[10]="world";
   n=strlen(str1);
   m=strlen(str2);
   i=n;

   while(j<m){
    str1[i]=str2[i];
    i++;
    j++;
   }
   printf("%s",str1);
    return 0;
}