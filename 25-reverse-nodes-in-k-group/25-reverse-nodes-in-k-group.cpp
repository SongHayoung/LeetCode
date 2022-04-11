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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        int n = k;
        ListNode* dummy = new ListNode();
        ListNode* tmp;
        ListNode* tail = head;
        while(n--) {
            tmp = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = tmp;
            if(!head && n) {
                return reverseKGroup(dummy->next, k - n);
            }
        }
        if(tmp) {
            tail->next = reverseKGroup(tmp, k);
        }
        return dummy->next;
    }
};