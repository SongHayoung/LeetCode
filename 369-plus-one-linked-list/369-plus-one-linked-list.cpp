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
    int solution(ListNode* node) {
        if(!node) return 1;
        int append = solution(node->next);
        node->val += append;
        if(node->val == 10) {
            node->val = 0;
            return 1;
        }
        return 0;
    }
public:
    ListNode* plusOne(ListNode* head) {
        int append = solution(head);
        if(append)
            head = new ListNode(1, head);
        return head;
    }
};