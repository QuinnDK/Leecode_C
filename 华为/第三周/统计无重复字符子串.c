#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "securec.h"
#define MAX 1000000

int countSubstrings(char* str){
    
    int i = 0, j = 0;
    int letters[30] = { 0 };
    int sum = 0;
    while (str[i]!='\0') {
        while (str[j]!='\0') {
            if (letters[str[j] - 'a'] == 0) {
                letters[str[j] - 'a'] = 1;
                j++;
            }else {
                break;
            }
        }
        sum += j - i;
        printf("%d\n",sum);
        letters[str[i] - 'a'] = 0;

        i++;

    }
    return sum;
}

int main(){
    char str[MAX];
    scanf("%s",str);
    int res=countSubstrings(str);
    printf("%d\n",res);
}