#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){};
};

ListNode* detectCycle(ListNode *head){
    if(head==NULL){
        return head;
    }
    ListNode* fast=head->next;
    ListNode* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        if(fast==slow){
            slow=head;
            fast=fast->next;//第一次相遇，slow回到起点，fast多走一步。
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    return NULL;
}

int main(){
    return 0;
}