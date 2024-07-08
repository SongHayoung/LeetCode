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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> mp;
        ListNode* run = head;
        while(run) {
            mp[run->val]++;
            run = run->next;
        }
        while(head && mp[head->val] != 1)
            head = head->next;
        
        run = head;
        
        while(run && run->next) {
            if(mp[run->next->val] == 1) run = run->next;
            else run->next = run->next->next;
        }
        
        
        return head;
    }
};