#include<iostream>
using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(nullptr) {}
};


ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//反转链表
ListNode* reverse(ListNode* head){
    if (head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* last=reverse(head->next);
    head->next->next=head;
    head->next=nullptr;
    return last;
}

//反转前N个
ListNode* successor=nullptr;
ListNode* reverseN(ListNode* head,int n){
    if (n==1){
        successor=head->next;
        return head;
    }
    ListNode* last=reverseN(head->next,n-1);
    head->next->next=head;
    head->next=successor;
    return last;
}

//反转 m,n 之间的部分
ListNode* reverseBetween(ListNode* head,int m,int n){
    if (m==1){
        return reverseN(head,n);
    }
    head->next=reverseBetween(head->next,m-1,n-1);
    return head;
}

ListNode* reverseBetween1(ListNode* head, int left, int right) {
        ListNode* result=new ListNode();
        result->next=head;
        ListNode* pre=result;

        for (int i=0;i<left-1;i++){
            pre=pre->next;
        }

        ListNode* cur=pre->next;
        for(int i=0;i<right-left;i++){
            ListNode* Next=cur->next;
            cur->next=Next->next;
            Next->next=pre->next;
            pre->next=Next;
        }
        return result->next;
    }