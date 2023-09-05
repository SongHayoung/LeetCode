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
    map<Node*, Node*> m;
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* newHead = new Node(head->val);
        Node* newNode = newHead;
        Node* node = head;
        m[head] = newHead;
        while(node != NULL) {
            if(node->next != NULL && !m.count(node->next)) {
                m[node->next] = new Node(node->next->val);
            }
            newNode->next = m[node->next];
            if(node->random != NULL && !m.count(node->random)) {
                m[node->random] = new Node(node->random->val);
            }
            newNode->random = m[node->random];
            
            node = node->next;
            newNode = newNode->next;
        }
        
        return newHead;
    }
};