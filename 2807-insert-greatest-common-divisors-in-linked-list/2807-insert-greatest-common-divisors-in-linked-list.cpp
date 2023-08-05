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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* res = head;
        ListNode* runner = head->next;
        ListNode* tail = res;
        while(runner) {
            int g = __gcd(tail->val, runner->val);
            tail->next = new ListNode(g);
            tail = tail->next;
            tail->next = runner;
            tail = tail->next;
            runner = runner->next;
        }
        return res;
    }
};