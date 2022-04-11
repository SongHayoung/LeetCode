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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* cur = dummy, *nxt = head;
        
        while(nxt and nxt->next) {
            ListNode* tmp = nxt->next;
            cur->next = tmp;
            nxt->next = tmp->next;
            tmp->next = nxt;
            cur = nxt;
            nxt = nxt->next;
        }
        
        return dummy->next;
    }
};