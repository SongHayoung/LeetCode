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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *res = head, *runner = head;
        while(runner) {
            for(int i = 0; i < m - 1 and runner; i++) runner = runner->next;
            if(!runner) break;
            ListNode* tail = runner;
            runner = runner->next;
            for(int i = 0; i < n and runner; i++) runner = runner->next;
            tail->next = runner;
        }
        return res;
    }
};