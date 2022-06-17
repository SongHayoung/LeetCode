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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(-1);
        ListNode* greater = new ListNode(-1);
        ListNode* l = less;
        ListNode* g = greater;
        while(head) {
            if(head->val < x) {
                l->next = head;
                l = l->next;
            } else {
                g->next = head;
                g = g->next;
            }
            head = head->next;
        }
        l->next = greater->next;
        g->next = nullptr;
        return less->next;
    }
};