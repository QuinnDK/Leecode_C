#include<iostream>
using namespace std;

typedef struct ListNode{
    int Val;
    struct ListNode * Next;
};

bool hasCycle(ListNode head){
    ListNode fast,slow;
    fast=slow=head;
    while(fast != NULL &&fast.Next!=NULL){
        fast=fast.Next.Next;
        slow=slow.Next;
        if (fast==slow){
            return true;
        }
    }
    return false;
}
