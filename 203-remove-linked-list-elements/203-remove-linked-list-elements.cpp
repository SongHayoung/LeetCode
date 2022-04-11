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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy, *cur = head;
        while(cur) {
            if(cur->val == val) {
                prev->next = cur->next;
            } else {
                prev = prev->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};