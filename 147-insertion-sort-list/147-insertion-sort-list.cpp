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
    bool eof = false;
    int dfs(ListNode* node, int dep, int target) {
        if(!node) {
            eof = true;
            return INT_MAX;
        }
        if(dep == target) return node->val;
        int nxt = dfs(node->next, dep + 1, target);
        if(nxt < node->val) {
            node->next->val = node->val;
            node->val = nxt;
        }
        return node->val;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        int dep = 1;
        while(!eof) {
            dfs(head, 1, dep++);
        }
        return head;
    }
};