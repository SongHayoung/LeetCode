/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* runner = node;
        while(runner->next->next) {
            runner->val = runner->next->val;
            runner = runner->next;
        }
        runner->val = runner->next->val;
        runner->next = NULL;
    }
};