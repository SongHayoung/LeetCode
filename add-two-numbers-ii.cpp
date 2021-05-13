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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* head = nullptr;
        int add = 0;
        while(!s1.empty() || !s2.empty()) {
            if(!s1.empty()) add += s1.top(), s1.pop();
            if(!s2.empty()) add += s2.top(), s2.pop();
            head = new ListNode(add % 10, head);
            add /= 10;
        }
        
        
        return add ? new ListNode(add, head) : head;
    }
};
