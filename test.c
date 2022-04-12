#include<stdio.h>

int main(){
    int countNum=0;
    char str[100]="123abc";
    for(int i=0;i<100;i++){
        if(str[i]>='0'&&str[i]<='9'){
            countNum++;
        }else{
            break;
        }
    }
    printf("countNum=%d\n",countNum);
}