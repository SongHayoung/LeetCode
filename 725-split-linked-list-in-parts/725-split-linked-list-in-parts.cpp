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
    int sizeOf(ListNode* head) {
        int res = 0;
        ListNode* runner = head;
        while(runner) {
            runner = runner->next;
            res++;
        }
        return res;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = sizeOf(head), idx = 0;
        int req = n / k, padding = n - k * req;
        vector<ListNode*> res(k);
        ListNode* runner = head;
        for(int i = 0; i < k and runner; i++) {
            res[i] = runner;
            ListNode* last = runner;
            for(int j = 0; j < req; j++) {
                last = runner;
                runner = runner->next;
            }
            if(padding > i) {
                last = runner;
                runner = runner->next;
            }
            if(last) last->next = nullptr;
        }
        return res;
    }
};