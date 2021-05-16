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
        queue<int> l, r;
        stack<int> reverse;
        ListNode* cur = head;
        for(int i = 1; i < left; i++) {
            l.push((int)cur->val);
            cur = cur->next;
        }
        for(int i = left; i <= right; i++) {
            reverse.push((int)cur->val);
            cur = cur->next;
        }
        while(cur != nullptr) {
            r.push((int)cur->val);
            cur = cur->next;
        }
        ListNode* newHead = new ListNode(), *prev;
        cur = newHead;
        while(!l.empty()) {
            cur->val = l.front();
            cur->next = new ListNode();
            prev = cur;
            cur = cur->next;
            l.pop();
        }
        while(!reverse.empty()) {
            cur->val = reverse.top();
            cur->next = new ListNode();
            prev = cur;
            cur = cur->next;
            reverse.pop();
        }
        while(!r.empty()) {
            cur->val = r.front();
            cur->next = new ListNode();
            prev = cur;
            cur = cur->next;
            r.pop();
        }
        prev->next = nullptr;
        return newHead;
    }
};
