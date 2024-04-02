/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* runner = head;
        while(runner) {
            Node* copy = new Node(runner->val);
            copy->next = runner->next;
            runner->next = copy;
            runner = copy->next;
        }
        runner = head;
        while(runner) {
            if(runner->random) runner->next->random = runner->random->next;
            runner = runner->next->next;
        }
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        runner = head;
        while(runner) {
            tail->next = runner->next;
            tail = tail->next;
            runner->next = runner->next->next;
            runner = runner->next;
        }
        return dummy->next;
    }
};