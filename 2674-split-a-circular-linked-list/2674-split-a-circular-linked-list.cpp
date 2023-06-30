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
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        ListNode* runner = list;
        while(runner->next != list) runner = runner->next;
        runner->next = nullptr;
        ListNode* slow = list, *fast = list;
        while(fast->next != nullptr and fast->next->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
            if(fast->next != nullptr) fast = fast->next;
        }
        if(fast->next != nullptr) fast = fast->next;
        ListNode* next = slow->next;
        slow->next = list;
        fast->next = next;
        return {list, next};
    }
};
