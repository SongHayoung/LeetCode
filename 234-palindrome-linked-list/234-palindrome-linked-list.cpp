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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        if(!head->next->next) return head->next->val == head->val;

        ListNode *mid = head, *tail = head, *prev = NULL, *nxt;
        while(tail->next and tail->next->next) {
            tail = tail->next->next;
            nxt = mid->next; //next mid
            mid->next = prev; //reverse
            prev = mid;
            mid = nxt;
        }
        //if size is odd move forward
        if(!tail->next) mid = mid->next;
        else {
            nxt = mid->next; //next mid
            mid->next = prev; //reverse
            prev = mid;
            mid = nxt;
        }
        
        while(mid != NULL and prev != NULL) {
            if(mid->val != prev->val) return false;
            mid = mid->next;
            prev = prev->next;
        }
        
        return !mid and !prev;
    }
};