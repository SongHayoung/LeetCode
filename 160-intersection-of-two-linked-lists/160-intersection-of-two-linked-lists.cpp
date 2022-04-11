/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> group;
        ListNode* cur = headA;
        while(cur != NULL) {
            group.insert(cur);
            cur = cur->next;
        }
        
        cur = headB;
        while(cur != NULL) {
            if(group.count(cur))
                return cur;
            cur = cur->next;
        }

        return NULL;
    }
};