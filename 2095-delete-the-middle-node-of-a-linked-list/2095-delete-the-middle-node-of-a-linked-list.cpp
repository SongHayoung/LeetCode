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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode *slow = head, *fast = head;
        while(fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next) {
            slow = slow->next;
        }
        ListNode* runner = head;
        while(runner->next != slow) runner = runner->next;
        runner->next = slow->next;
        return head;
    }
};