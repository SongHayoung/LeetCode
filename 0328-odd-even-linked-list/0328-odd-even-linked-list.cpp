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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* secondTail = head->next;
        ListNode* secondHead = head->next;
        ListNode* headTail = head;
        
        while(secondTail->next) {
            headTail->next = secondTail->next;
            headTail = headTail->next;
            secondTail->next = secondTail->next->next;
            headTail->next = secondHead;
            if(secondTail->next)
                secondTail = secondTail->next;
        }
        return head;
    }
};