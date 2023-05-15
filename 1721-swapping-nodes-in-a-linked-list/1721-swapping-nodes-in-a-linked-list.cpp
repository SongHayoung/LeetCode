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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* lastNode = head;
        ListNode* target1 = head;
        ListNode* target2 = head;
        
        for(int i = 1; i < k; i++) {
            lastNode = lastNode->next;
            target1 = target1->next;
        }
        
        while(lastNode->next != nullptr) {
            lastNode = lastNode->next;
            target2 = target2->next;
        }
        swap(target1->val, target2->val);

        return head;
    }
};