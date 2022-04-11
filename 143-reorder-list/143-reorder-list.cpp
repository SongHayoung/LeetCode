/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        while(head) {
            nodes.push_back(head);
            head = head->next;
        }
        int l = 0, r = nodes.size() - 1;
        while(l <= r) {
            nodes[l++]->next = nodes[r];
            if(l < r)
                nodes[r--]->next = nodes[l];
            else nodes[r]->next = nullptr;
        }
    }
};