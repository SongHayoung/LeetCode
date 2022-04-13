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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> n(nums.begin(), nums.end());
        int res = 0;
        bool consequtive = false;
        while(head) {
            if(!n.count(head->val)) {
                if(consequtive) res++;
                consequtive = false;
            } else consequtive = true;
            head = head->next;
        }
        return res + consequtive;
    }
};