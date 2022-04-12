#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h> 

typedef struct
{
    char YearMonthDay[11];
    char HourMinuteSecond[9];
    char Millisecond[4];
}OrderTime;
typedef struct{
    char HourMinuteSecond[20];
    int count;
}FirstOrder;

bool isFind(OrderTime order,FirstOrder* firstorder,int len){
    char* copyOrder=malloc(20*sizeof(char));
    int j=0;
    int count=0;
    while(j<11){
        copyOrder[count++]=order.YearMonthDay[j++];
    }
    j=0;
    while(j<9){
        copyOrder[count++]=order.HourMinuteSecond[j++];
    }
    for(int i=0;i<len;i++){
        if(strcmp(firstorder[i].HourMinuteSecond,copyOrder)==0){
            return true;
        }
    }
    return false;
}

int CountFree(OrderTime* order,int n){
    FirstOrder firstorder[n];
    for(int i=0;i<n;i++){
        if(isFind(order[i],firstorder,n)){

        }else{
            
        }
    }
}


int main(){
    int n;
    scanf("%d",&n);
    OrderTime order[n];
    for(int i=0;i<n;i++){
        char first[11];
        scanf("%s",first);
        strcpy(order[i].YearMonthDay,first);

        char twice[13];
        scanf("%s",twice);
        //printf("%s %ld",twice,strlen(twice));
        bool flag=false;
        int countH=0;
        int countM=0;
        for(int j=0;j<strlen(twice);j++){
            if(twice[j]=='.'){
                flag=true;
                continue;
            }
            if(flag==false){
                order[i].HourMinuteSecond[countH++]=twice[j];
            }
            order[i].HourMinuteSecond[countH]='\0';
            if(flag==true){
                order[i].Millisecond[countM++]=twice[j];
            }
        }
    }
    int result=0;
    result=CountFree(order,n);
    printf("%d",result);

}