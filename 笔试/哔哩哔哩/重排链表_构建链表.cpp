#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<sstream>

using namespace std;

struct Node {
  int val;
  Node* next;
};

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
void reorderList(Node* head) {
    vector<Node*> myVec;
       
    Node *ptr = head, *endPtr = head;
    while (ptr != NULL) {
        myVec.push_back(ptr);
        ptr = ptr->next;
    }
    int vecSize = myVec.size();
    if (vecSize <= 2) {
        return;
    }
    endPtr = head;
    endPtr->next = myVec[vecSize - 1];
    endPtr = endPtr->next;
    int nowIndex = 1;
    int endIndex = vecSize / 2;
    if (vecSize % 2 == 0){
        endIndex -= 1;
    }
    while (nowIndex < endIndex) {
        endPtr->next = myVec[nowIndex];
        endPtr = endPtr->next;
        endPtr->next = myVec[vecSize - nowIndex - 1];
        endPtr = endPtr->next;
        ++nowIndex;
    }
    endPtr->next = myVec[nowIndex++];
    endPtr = endPtr->next;
    if (vecSize % 2 == 0) {
        endPtr->next = myVec[nowIndex++];
        endPtr = endPtr->next;
    }
    endPtr->next = NULL;
}

/******************************结束写代码******************************/

Node *createList_array(vector<int>&a , int n){
    Node *root = new Node();
    Node *pnode = root;
    for (int i = 0; i < n - 1; ++i){
        root->val = a[i];
        root->next = NULL;
        Node *p = new Node();
        p->val = a[i + 1];
        p->next = NULL;
        root->next = p;
        root = root->next;
    }
    root->next = NULL;
    return pnode;
}

void display(Node *p,int num){
    Node *temp=p;
    while (num--)
    {
        cout<<temp->val<<",";
        temp=temp->next;
        if(num-1==0){
            break;
        }
    }
    cout<<temp->val;
}

int main() {
    vector<char> s;
    char s1;
    // string str;
    // cin >> str;
    // vector<int> nums2;

    // int t = 0;
    // int l = 0;
    // // cout << str.size();
    // while(l < str.size()) {

    //     if(str[l] == ',') {
    //         nums2.push_back(t);
    //         t = 0;
    //     } else {
    //         t = t * 10 + str[l] - '0';
    //     }   
    //     l++;
    // }
    // nums2.push_back(t);
    // for(auto x : nums2) cout << x << " ";
    // cout << endl;
    string str;

    // int i = atoi(str.c_str());

    cin>>str;
    stringstream t(str);
    vector<int> nums;

    while(getline(t,str,',')){
        int t=stoi(str);
        nums.push_back(t);
    }
    // for(auto it:nums){
    //     cout<<it;
    // }

    // while(cin>>s1){
    //     if(s1 !=','){
    //         s.push_back(s1);
    //     }
    //     if(s1=='\n'){
    //         break;
    //     }
    // }
    // vector<int> nums(s.size());
    // for(int i=0;i<s.size();i++){
    //     nums[i]=s[i]-'0';
    // }
    
    Node* head=createList_array(nums,nums.size());
    reorderList(head);
    display(head,nums.size());
}
