#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define TIMELEN 30

typedef struct{
    char Time[TIMELEN];
    char Millisecond[TIMELEN];
}Order;

typedef struct{
    Order *order;
    int res;
}FisrtOrder;

//记录每秒第一个下单的订单，并返回订单数量
int getFirstOrder(Order *order, int count, FisrtOrder *firstOrder){
    int firstOrderCount = 0;
    int firstOrderIndex = 0;
    for(int i=0;i<count;i++){
        bool isFirst = true;
        for(int j=0;j<firstOrderIndex;j++){
            if(strcmp(order[i].Time,firstOrder[j].order->Time)==0){
                isFirst = false;
                if(strcmp(order[i].Millisecond,firstOrder[j].order->Millisecond)==0){
                    firstOrder[j].res++;
                    break;
                }else if(strcmp(order[i].Millisecond,firstOrder[j].order->Millisecond)<0){
                    strcpy(firstOrder[j].order->Millisecond,order[i].Millisecond);
                    firstOrder[j].res=1;
                    break;
                }else if(strcmp(order[i].Millisecond,firstOrder[j].order->Millisecond)>0){
                    break;
                }
            }
        }
        if(isFirst){
            firstOrder[firstOrderIndex].order = &order[i];
            firstOrder[firstOrderIndex].res=1;
            firstOrderIndex++;
        }
    }
    for(int k=0;k<firstOrderIndex;k++){
        firstOrderCount+=firstOrder[k].res;
    }
    return firstOrderCount;
}

int main(){
    int n;
    scanf("%d",&n);
    Order order[n];
    for(int i=0;i<n;i++){
        scanf("%s %s",order[i].Time,order[i].Millisecond);
    }
    for(int i=0;i<n;i++){
        strncat(order[i].Time,order[i].Millisecond,8);
        //获取.后面的数字
        int j=0;
        for(;j+9<strlen(order[i].Millisecond);j++){
            order[i].Millisecond[j]=order[i].Millisecond[j+9];
        }
        order[i].Millisecond[j]='\0';
    }
    FisrtOrder firstOrder[n];
    int firstOrderCount = getFirstOrder(order, n, firstOrder);
    printf("%d\n",firstOrderCount);

}