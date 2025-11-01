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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* runner = dummy;
        unordered_set<int> us(begin(nums), end(nums));
        while(head) {
            if(!us.count(head->val)) {
                runner->next = new ListNode(head->val);
                runner = runner->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};