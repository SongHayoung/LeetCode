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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        for(int i = 0; i < n; i++) {
		tail = tail->next;
	}
	ListNode* dummy = new ListNode(-1,head);
	ListNode* prev = dummy;
	while(tail) {
	prev = prev->next;
	tail = tail->next;
	}
	prev -> next = prev->next->next;
	return dummy->next;
    }
};
