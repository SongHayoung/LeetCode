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
    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        while(head) {
            auto nxt = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = nxt;
        }
        
        return dummy->next;
    }
public:
    int pairSum(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while(fast) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = reverse(slow);
        int res = 0;
        while(second) {
            res = max(res, second->val + head->val);
            second = second->next;
            head = head->next;
        }
        return res;
    }
};