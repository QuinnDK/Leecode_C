#include<iostream>
using namespace std;

typedef struct ListNode{
    /* data */
    int Val;
    struct ListNode * Next;
};

ListNode * creatList(){
    ListNode * start=(ListNode*)malloc(sizeof(ListNode));
    ListNode *cur=start;
    for(int i=0;i<5;i++){
        ListNode * temp=(ListNode*)malloc(sizeof(ListNode));
        temp->Val=i;
        temp->Next=NULL;
        cur->Next=temp;
        cur=cur->Next;

    }
    return start;
}
void display(ListNode *p){
    ListNode *temp=p;
    while (temp->Next)
    {
        temp=temp->Next;
        cout<<temp->Val<<endl;
    }
    
}
int main(){
    ListNode *list;
    list=creatList();
    display(list);
}
