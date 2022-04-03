#include <stdio.h>
#include "securec.h"

#define STR_MAX_LEN 1000
#define ARR_MAX_LEN 100

// 待实现函数，在此函数中填入答题代码
void GetNTimesCharacter(int nValue, char **strings, int stringsSize, char *output, int outputSize) 
{
    char assic_all[128];
    memset(assic_all,1,128);
    for(int i=0;i<stringsSize;i++){
        int assic_cur[128]={0};
        int j=0;
        while(strings[i][j]!='\0'){
            assic_cur[strings[i][j]-'\0']++;
            ++j;
        }
        for(int i=0;i<128;i++){
            if(assic_cur[i]<nValue){
                assic_all[i]=0;
            }
        }
    }
    output[0]='[';
    int end=1;
    for(int i=0;i<128;++i){
        if(assic_all[i]==1){
            output[end++]=i;
            output[end++]=' ';
        }
    }
    if(end==1){
        output[end]=']';
    }else{
        output[end--]=']';
    }
    output[++end]='\0';
}

int main(void) 
{
    int nValue;
    if (scanf_s("%d", &nValue) != 1) { return -1; }
    int stringsSize = 0;  
    if (scanf_s("%d", &stringsSize) != 1) { return -1; } 

    char buf[ARR_MAX_LEN][STR_MAX_LEN];
    char *strings[ARR_MAX_LEN];
    for (int i = 0; i < stringsSize; i++) {
        if (scanf_s("%s\n", &buf[i], STR_MAX_LEN) != 1) { return -1; }
        strings[i] = buf[i];
    }
    
    char output[STR_MAX_LEN];
    GetNTimesCharacter(nValue, strings, stringsSize, output, STR_MAX_LEN);
    printf("%s", output);
    
    return 0;
}
