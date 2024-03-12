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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* runner = dummy;
        unordered_set<int> us;
        vector<pair<int, ListNode*>> st;
        int sum = 0;
        while(runner) {
            sum += runner->val;
            while(runner->next and runner->next->val == 0)
                runner->next = runner->next->next;
            if(us.count(sum)) {
                while(!st.empty() and st.back().first != sum) {
                    us.erase(st.back().first);
                    st.pop_back();
                }
                st.back().second->next = runner->next;
                sum = st.back().first;
            } else {
                us.insert(sum);
                st.push_back({sum, runner});
            }
            
            runner = runner->next;
        }

        return dummy->next;
    }
};