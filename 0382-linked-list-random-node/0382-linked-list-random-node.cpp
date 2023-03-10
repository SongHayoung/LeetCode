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
    ListNode* node;
public:
    Solution(ListNode *head) {
        node = head;
    }

    int getRandom() {
        int res = -1, n = 1;
        ListNode* runner = node;
        while(runner) {
            if(rand() % n == 0) res = runner->val;
            n++;
            runner = runner->next;
        }
        return res;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */