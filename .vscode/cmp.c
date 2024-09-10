#include <stdio.h>
#include <string.h>
int compare(char *str1,char *str2){
    int i=0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
        return str1[i]-str2[i];
        i++;
    }
    if(str1[i] == '\0' || str2[i]=='\0')
    {
        return 0;
    }
}
int main() {
   int i=0;
   char str1[]="hello";
   char str2[]="hello";
   int k=compare(str1,str2);
   if(k==0){
    printf("equal");
   }
   else{
    printf("not equal");
   }
    return 0;
}