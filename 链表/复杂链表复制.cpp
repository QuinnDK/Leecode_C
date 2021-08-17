#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head){
    if (head==nullptr) return nullptr;
    Node *cur=head;

    unordered_map<Node*,Node*> map;

    while(cur!=nullptr){
        map[cur]=new Node(cur->val); //键为原链表节点。值为新链表节点；
        cur=cur->next;
    }
    cur=head;

    while (cur!=nullptr){
        map[cur]->next=map[cur->next];
        map[cur]->random=map[cur->random];
        cur=cur->next;
    }
    return map[head];
}