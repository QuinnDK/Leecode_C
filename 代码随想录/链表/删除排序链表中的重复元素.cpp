#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};

ListNode* deleteDuplicates(ListNode* head){
    if(head==NULL) return head;
    ListNode* slow=head;
    ListNode* fast=head->next;

    while(fast !=NULL){
        if(fast->val!=slow->val){
            fast=fast->next;
            slow=slow->next;
        }else{
            fast=fast->next;
            slow->next=fast;
        }

    }
    return head;
}

int main(){
    return 0;
}