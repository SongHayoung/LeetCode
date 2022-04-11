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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        ListNode* target = head;
        while(n--) {
            tail = tail->next;
        }
        if(tail == nullptr) {
            return head -> next;
        }
        
        while(tail->next != nullptr) {
            target = target->next;
            tail = tail->next;
        }
        target->next = target->next->next;
        
        return head;
    }
};
