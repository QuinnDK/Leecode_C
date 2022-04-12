#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    char str1[10]="Hello";
    char str2[]="World";
    char str3[]={'H','e','l','l','o'};  
    printf("%ld %ld %ld",sizeof(str1),sizeof(str2),sizeof(str3));
}