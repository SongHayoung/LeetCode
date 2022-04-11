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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*> reverse;
        ListNode* preHead = new ListNode(-1, head), *cur = preHead, *origin = head;
        for(int i = 1; i < left; i++) {
            cur = cur->next;
        }
        
        origin = cur->next;
        
        for(int i = left; i <= right; i++) {
            reverse.push(origin);
            origin = origin->next;
        }
        
        while(!reverse.empty()) {
            cur->next = reverse.top();
            reverse.pop();
            cur = cur->next;
        }
        
        cur->next = origin;
        return preHead->next;
    }
};