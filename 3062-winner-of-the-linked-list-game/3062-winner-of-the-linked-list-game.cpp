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
    string gameResult(ListNode* head) {
        int res = 0;
        ListNode* even = head;
        ListNode* odd = even->next;
        
        
        while(1) {
            res += even->val > odd->val ? 1 : -1;
            if(!odd->next) break;
            even = odd->next;
            odd = even->next;
        }
        
        
        return res == 0 ? "Tie" : res > 0 ? "Even" : "Odd";
    }
};