/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    map<int, Node*> m;
    void explore(Node* n) {
        if(!n) return;
        m[n->val] = n;
        explore(n->left);
        explore(n->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        explore(root);
        for(auto i = begin(m); i != end(m); i++) {
            Node* n = (i)->second;
            if(i == begin(m)) n->left = (prev(end(m)))->second;
            else n->left = prev(i)->second;
            if(i == prev(end(m))) n->right = (begin(m))->second;
            else n->right = next(i)->second;
        }
        return m.begin()->second;
    }
};