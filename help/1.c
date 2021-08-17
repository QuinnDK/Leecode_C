#include<stdio.h>
char *returnStr(){
    //char *p=(char*)malloc(13*sizeof(char));
    char *p="hello world";
    return p;
}
int main(){
    char *str=NULL;
    str= returnStr();
    printf("%s\n",str);
    return 0;
}