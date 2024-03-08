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
    ListNode* frequenciesOfElements(ListNode* head) {
        ListNode* runner = head;
        unordered_map<int, int> freq;
        while(runner) {
            freq[runner->val] += 1;
            runner = runner->next;
        }
        runner = head;
        vector<int> S;
        for(auto& [k,v] : freq) S.push_back(v);
        sort(begin(S), end(S));
        while(S.size()) {
            runner->val = S.back();
            S.pop_back();
            if(S.size()) runner = runner->next;
        }
        runner->next = nullptr;
        return head;
    }
};