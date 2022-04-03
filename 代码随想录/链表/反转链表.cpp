#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(NULL){}
};

ListNode* reverseList(ListNode* head){
    ListNode* tmp;
    ListNode* cur=head;
    ListNode* pre=NULL;

    while(cur){
        tmp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    return pre;
}