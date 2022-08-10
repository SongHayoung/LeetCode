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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        int last = head->val, p = 0;
        while(head->next) {
            int now = head->val, next = head->next->val;
            if(last < now and next < now) critical.push_back(p);
            else if(now < last and now < next) critical.push_back(p);
            p++;
            last = head->val;
            head = head->next;
        }
        if(critical.size() < 2) return {-1,-1};
        int mi = INT_MAX, ma = critical.back() - critical.front();
        for(int i = 0; i < critical.size() - 1; i++) {
            mi = min(mi, critical[i+1] - critical[i]);
        }
        return {mi,ma};
    }
};