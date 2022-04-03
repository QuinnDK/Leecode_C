#include<bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(NULL){}
};

ListNode* getIntersectionNode(ListNode* headA,ListNode* headB){
    ListNode* curA=headA;
    ListNode* curB=headB;
    int lenA=0;
    int lenB=0;

    while(curA){
        lenA++;
        curA=curA->next;
    }
    while(curB){
        lenB++;
        curB=curB->next;
    }

    curA=headA;
    curB=headB;

    if(lenB>lenA){
        swap(lenA,lenB);
        swap(curA,curB);
    }

    int gap=lenA-lenB;
    while (gap--)
    {
        curA=curA->next;
    }
    while(curA){
        if(curA==curB){
            return curA;
        }
        curA=curA->next;
        curB=curB->next;
    }
    return NULL;
    
}

int main(){
    return 0;
}