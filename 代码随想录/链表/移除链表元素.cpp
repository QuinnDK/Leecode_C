#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){};
};

//不设置虚拟头结点
ListNode* removeElements1(ListNode* head,int val){
    //删除头结点
    while(head !=NULL && head->val==val){
        ListNode* tmp=head;
        head=head->next;
        delete tmp;
    }
    //删除非头结点
    ListNode* cur =head;
    while(cur !=NULL && cur->next!=NULL){
        if(cur->next->val==val){
            ListNode* tmp=cur->next;
            cur->next=cur->next->next;
            delete tmp;
        }else{
            cur=cur->next;
        }
    }
    return head;
}

//设置虚拟节点
ListNode* removeElements(ListNode* head, int val){
    ListNode* dummyHead=new ListNode(0);
    dummyHead->next=head;
    ListNode* cur=dummyHead;

    while(cur->next!=NULL){
        if(cur->next->val==val){
            ListNode* tmp=cur->next;
            cur->next=cur->next->next;
            delete tmp;
        }else{
            cur=cur->next;
        }
    }
    head=dummyHead->next;
    delete dummyHead;
    return head;
}

int mian(){

}