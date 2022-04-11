/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    vector<Node*> lvls;
    void travel(Node* node, int lvl) {
        if(!node) return;
        if(lvls[lvl]) {
            lvls[lvl]->next = node;
        }
        lvls[lvl] = node;
        travel(node->left, lvl+1);
        travel(node->right, lvl+1);
    }
public:
    Node* connect(Node* root) {
        lvls = vector<Node*>(6001,NULL);
        travel(root, 0);
        return root;
    }
};