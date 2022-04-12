#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#include<stdbool.h>
#define MAX_LEN 1000

int compare(const void* a,const void* b){
    char* a1=(char*)a;
    char* b1=(char*)b;
    return *a1-*b1;
}
void CharacterSort(char* intputStr,char* output,int outputSize){
    int numCount=0,charCount=0;
    int charIndex[outputSize];
    memset(charIndex,0,sizeof(charIndex));
    
    for(int i=0;i<outputSize;i++){
        if(intputStr[i]>='0'&&intputStr[i]<='9'){
            charIndex[i]=0;
            numCount++;
        }else if(intputStr[i]>='A'&&intputStr[i]<='z'){
            charIndex[i]=1;
            charCount++;
        }
    }
    char numtemp[numCount];
    char chartemp[charCount];
    int numIndex=0,charIndexl=0;
    for(int i=0;i<outputSize;i++){
        if(charIndex[i]==0){
            numtemp[numIndex++]=intputStr[i];
        }else if(charIndex[i]==1){
            chartemp[charIndexl]=intputStr[i];
            charIndexl++;
        }
    }
    //对数字排序
    for(int i=0;i<numCount;i++){
        for(int j=0;j<numCount-i-1;j++){
            if(numtemp[j]>numtemp[j+1]){
                char temp=numtemp[j];
                numtemp[j]=numtemp[j+1];
                numtemp[j+1]=temp;
            }
        }
    }
    qsort(chartemp,charCount,sizeof(char),compare);
    char* newarray=malloc(sizeof(char)*outputSize);
    memset(newarray,0,sizeof(char)*outputSize);
    int newIndex=0;
    int dex=0;
    bool flag=true;
    for(int i=0;i<charCount;i++){
        if(chartemp[i]>='a'){
            if(flag){
                dex=i;
                flag=false;
            }
            newarray[newIndex++]=chartemp[i];
        }
    }
    strncat(newarray,chartemp,dex);
    printf("%s\n",newarray);
    numIndex=0,charIndexl=0;
    for(int i=0;i<outputSize;i++){
        if(charIndex[i]==0){
            output[i]=numtemp[numIndex++];
        }else{
            output[i]=newarray[charIndexl++];
        }
    }
    free(newarray);
    return;
}

int main(){
    char str[MAX_LEN];
    scanf("%s",str);
    char output[MAX_LEN];
    CharacterSort(str,output,strlen(str));
    printf("%s\n",output);
    return 0;
}