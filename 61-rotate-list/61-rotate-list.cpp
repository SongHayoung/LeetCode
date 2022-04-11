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
    ListNode* rotateRight(ListNode* head, int k) {
        int size = head == nullptr ? 0 : 1;
        if(!size)
            return head;
        
        ListNode* current = head;
        while(current->next != nullptr) {
            current = current->next;
            size++;
        }
        current->next = head;
        
        k %= size;
        
        int move = size - k - 1;
        current = head;
        while(move--) {
            current = current->next;
        }
        
        head = current->next;
        current->next = nullptr;

        return head;
    }
};