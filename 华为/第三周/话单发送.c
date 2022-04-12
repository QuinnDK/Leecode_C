#include<stdio.h>

typedef struct{
    int capNum;
    int priority;
}Bill;

int comparator(const void *p, const void *q)
{
    Bill arg1 = *(Bill*)p;
    Bill arg2 = *(Bill*)q;
    if(arg1.priority!=arg2.priority){
        return arg1.priority-arg2.priority;
    }else{
        return arg1.capNum-arg2.capNum;
    }
}

void sort(Bill* bill,int num){
    qsort(bill, num, sizeof(Bill), comparator);
}

int main(){
    int  cap;
    scanf("%d",&cap);
    int num;
    scanf("%d",&num);
    Bill bill[num];
    for(int i=0;i<num;i++){
        scanf("%d",&bill[i].capNum);
    }
    for(int i=0;i<num;i++){
        scanf("%d",&bill[i].priority);
    }
    sort(bill,num);
    for(int i=0;i<num;i++){
        printf("%d %d\n",bill[i].capNum,bill[i].priority);
    }
    int count =0;
    int result=0;
    for(int i=0;i<num;i++){
        count+=bill[i].capNum;
        if(count<=cap){
            ++result;
        }
    }
    printf("%d",result);

}