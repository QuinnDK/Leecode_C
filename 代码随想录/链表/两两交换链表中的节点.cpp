#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(NULL){}
};

ListNode* swapPairs(ListNode* head){
    ListNode* dymmyHead=new ListNode(0);
    dymmyHead->next=head;
    ListNode* cur=dymmyHead;

    while(cur->next!=NULL && cur->next->next!=NULL){
        ListNode* tmp=cur->next;
        ListNode* tmp1=cur->next->next->next;
        cur->next=cur->next->next;
        cur->next->next=tmp;
        cur->next->next->next=tmp1;

        cur=cur->next->next;
    }
    return dymmyHead->next;
}