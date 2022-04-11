/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
private:
    Node* findNode(Node* head, int value) {
        Node* cur = head;
        if(head->val != value) {
            while(cur->next != head && !(
                    (cur->next->val >= value && cur->val <= value)  ||
                    (cur->next->val >= value && cur->val > value && cur->val > cur->next->val) ||
                    (cur->next->val <= value && cur->val < value && cur->val > cur->next->val))) {
                cur = cur->next;
            }
        }
        return cur;
    }
public:
    Node* insert(Node* head, int insertVal) {
        if(head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
        } else {
            Node *node = findNode(head, insertVal);
            node->next = new Node(insertVal, node->next);
        }
        return head;
    }
};
