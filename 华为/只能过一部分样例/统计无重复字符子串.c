#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "securec.h"
#define MAX 1000000

void substr(char *dst,char *src, int n,int m) /*n为长度，m为位置*/
{
    char *p = src;
    char *q = dst;
    int len = strlen(src);
    if(n>len) n = len-m;    
    if(m<0) m=0;    
    if(m>len) return;
    p += m;
    while(n--) *(q++) = *(p++);
    *(q++)='\0'; 
}
int countSubstrings(char * s){
    int freq[26]={0};
    int len=1;
    int res=0;
    for(;len<=strlen(s);len++){
        for(int j=0;j<strlen(s);j++){
            if(j+len>strlen(s)) break;
            char* temp=malloc(sizeof(char)*len);
            substr(temp,s,len,j);
            for(int i=0;i<len;i++){
                if(freq[temp[i]-'a']){
                    memset(freq, 0, sizeof(int)*26);
                    free(temp);
                    break;
                }
                freq[temp[i]-'a']=1;
                if(i==len-1){
                    ++res;
                    memset(freq, 0, sizeof(int)*26);
                    free(temp);
                }
            }
        }
    }
    return res;
}

int main(){
    char str[MAX];
    scanf("%s",str);
    int res=countSubstrings(str);
    printf("%d\n",res);
}