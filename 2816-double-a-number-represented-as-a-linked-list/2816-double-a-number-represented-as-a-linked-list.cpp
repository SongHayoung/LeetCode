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
    ListNode* doubleIt(ListNode* head) {
        vector<ListNode*> st;
        ListNode* runner = head;
        while(runner) {
            st.push_back(runner);
            runner = runner->next;
        }
        ListNode* res = nullptr;
        int carry = 0;
        while(st.size()) {
            res = st.back(); st.pop_back();
            res->val = (res->val * 2 + carry);
            carry = (res->val) / 10;
            res->val %= 10;
        }
        if(carry) {
            ListNode* node = new ListNode(carry, res);
            res = node;
        }
        return res;
    }
};
