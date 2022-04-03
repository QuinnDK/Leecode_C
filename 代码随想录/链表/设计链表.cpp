#include<bits/stdc++.h>
using namespace std;

class MyLinkedList{
public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(NULL){}
    };

    MyLinkedList() {
        dummyHead = new LinkedNode(0);
        size=0;
    }

    int get(int index) {
        if(index<0 || index>size-1){
            return -1;
        }
        LinkedNode* cur=dummyHead->next;
        while(index--){
            cur=cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        LinkedNode* newNode=new LinkedNode(val);
        newNode->next=dummyHead->next;
        dummyHead->next=newNode;
        size++;
    }

    void addAtTail(int val) {
        LinkedNode* newNode=new LinkedNode(val);
        LinkedNode* cur=dummyHead;
        while(cur->next !=NULL){
            cur=cur->next;
        }
        cur->next=newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index>size){
            return;
        }
        LinkedNode* newNode =new LinkedNode(val);
        LinkedNode* cur=dummyHead;
        while(index--){
            cur=cur->next;
        }
        newNode->next=cur->next;
        cur->next=newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if(index >=size || index<0){
            return;
        }
        LinkedNode* cur=dummyHead;
        while(index--){
            cur=cur->next;
        }
        LinkedNode* tmp= cur->next;
        cur->next=cur->next->next;
        delete tmp;
        size--;
    }

    void printLinkedList(){
        LinkedNode *cur =dummyHead;
        while(cur->next!=NULL){
            cout<<cur->next->val<< " ";
            cur=cur->next;
        }
        cout<<endl;
    }
private:
    int size;
    LinkedNode* dummyHead;
};