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
    ListNode* sortList(ListNode* left) {
        if(!left or !(left->next)) return left;
        auto right = left, half = left;
        while(right->next != NULL and right->next->next != NULL) {
            half = half->next;
            right = right->next->next;
        }
        right = half->next;
        half->next = NULL;
        return merge(sortList(left), sortList(right));
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* tail = dummy;
        while(left != NULL and right != NULL) {
            if(left->val > right->val) {
                tail->next = right;
                right = right->next;
            } else {
                tail->next = left;
                left = left->next;
            }
            tail = tail->next;
        }
        tail->next = left ? left : right;

        return dummy->next;
    }
};