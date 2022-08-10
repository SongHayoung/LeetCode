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
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* runner = head->next, *last = head;
        
        while(runner) {
            ListNode* next = runner->next;
            if(runner->val < 0) {
                runner->next = dummy->next;
                dummy->next = runner;
                last->next = next;
            } else last = runner;
            
            runner = next;
        }
        
        return dummy->next;
    }
};