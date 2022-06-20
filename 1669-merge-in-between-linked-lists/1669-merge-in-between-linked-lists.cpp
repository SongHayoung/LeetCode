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
    ListNode* getNthNode(ListNode* node, int n) {
        ListNode* runner = node;
        while(n--) {
            runner = runner->next;
        }
        return runner;
    }
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tail = list2;
        while(tail->next) {
            tail = tail->next;
        }
        tail->next = getNthNode(list1, b + 1);
        getNthNode(list1, a - 1)->next = list2;
        return list1;
    }
};