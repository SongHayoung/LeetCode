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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *slow = head, *fast = head;
        while(fast->next and fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        if(!fast->next or !fast->next->next) return NULL;
        
        ListNode* res = head;
        while(res != slow) {
            slow = slow->next;
            res = res->next;
        }
        return res;
    }
};