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
    ListNode* removeNodes(ListNode* head) {
        vector<int> st;
        ListNode* runner = head;
        while(runner) {
            while(st.size() and st.back() < runner->val) {
                st.pop_back();
            }
            st.push_back(runner->val);
            runner = runner->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        for(int i = 0; i < st.size(); i++) {
            ListNode* now = new ListNode(st[i]);
            tail->next = now;
            tail = now;
        }
        return dummy->next;
    }
};
