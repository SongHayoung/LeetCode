/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    pair<Node*, Node*> helper(Node* node) {
        Node* head = node;
        Node* tail = node;
        while(tail) {
            if(tail->child) {
                auto tmp = tail->next;
                auto [childHead, childTail] = helper(tail->child);
                tail->child = nullptr;
                
                tail->next = childHead;
                childHead->prev = tail;
                
                childTail->next = tmp;
                if(tmp != nullptr)
                    tmp->prev = childTail;
                
                tail = childTail;
            }
            node = tail;
            tail = tail->next;
        }
        return {head, node};
    }
public:
    Node* flatten(Node* head) {
        return helper(head).first;
    }
};