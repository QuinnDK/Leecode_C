#include<bits/stdc++.h>
using namespace std;

struct ListNode {
 int val;
 struct ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
public:
    ListNode* solve(vector<ListNode*>& a) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* cur_node = dummy_head;
        int size = a.size();
        vector<int> isDeal(size, 0);
        int cur_size = size;
        while (cur_size != 0) {
            for (int i = 0; i < size; i++) {
                if (a[i] == nullptr) {
                    if (isDeal[i] == 0) {
                        isDeal[i] = 1;
                        cur_size--;
                    }
                    continue;
                }

                cur_node->next = a[i];
                a[i] = a[i]->next;
                cur_node = cur_node->next;
            }
        }
        return dummy_head->next;

    }
};