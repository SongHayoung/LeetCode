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
    ListNode* cut(ListNode* head, int req) {
        ListNode* runner = head;
        while(runner->next and --req) {
            runner = runner->next;
        }
        return runner;
    }
    int sizeOf(ListNode* node) {
        int res = 0;
        ListNode* runner = node;
        while(runner) {
            runner = runner->next;
            res++;
        }
        return res;
    }
    ListNode* reverse(ListNode* node) {
        ListNode* head = node;
        while(node->next) {
            ListNode* next = node->next;
            node->next = next->next;
            next->next = head;
            head = next;
        }
        return head;
    }
    void connect(ListNode* A, ListNode* B) {
        ListNode* runner = A;
        while(runner->next) runner = runner->next;
        runner->next = B;
    }
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int size = 1;
        ListNode* runner = head;
        vector<ListNode*> nodes;
        while(runner) {
            nodes.push_back(runner);
            auto tail = cut(runner,size++);
            runner = tail->next;
            tail->next = nullptr;
        }
        for(int i = 0; i < nodes.size(); i++) {
            int size = sizeOf(nodes[i]);
            if(size & 1) continue;
            nodes[i] = reverse(nodes[i]);
        }
        for(int i = 0; i < nodes.size() - 1; i++) {
            connect(nodes[i], nodes[i + 1]);
        }
        return nodes[0];
    }
};