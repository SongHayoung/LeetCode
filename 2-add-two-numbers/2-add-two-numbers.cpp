class Solution {
private:
    ListNode* add(ListNode* l1, ListNode* l2, int val) {
        if(l2 == nullptr)
            return new ListNode(l1->val + val);
        else
            return new ListNode(l1->val + l2->val + val);
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* solution = new ListNode;
        ListNode* cur = solution;
        int val = 0;
        while(l1 != nullptr && l2 != nullptr) {
            cur->next = add(l1, l2, val);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
            if(cur->val >= 10) {
                cur->val -= 10;
                val = 1;
            } else  {
                val = 0;
            }
        }

        while(l1 != nullptr) {
            cur->next = add(l1, nullptr, val);
            cur = cur->next;
            l1 = l1->next;
            if(cur->val >= 10) {
                cur->val -= 10;
                val = 1;
            } else  {
                val = 0;
            }
        }

        while(l2 != nullptr) {
            cur->next = add(l2, nullptr, val);
            cur = cur->next;
            l2 = l2->next;
            if(cur->val >= 10) {
                cur->val -= 10;
                val = 1;
            } else  {
                val = 0;
            }
        }

        if(val)
            cur->next = new ListNode(1);

        return solution->next;
    }
};