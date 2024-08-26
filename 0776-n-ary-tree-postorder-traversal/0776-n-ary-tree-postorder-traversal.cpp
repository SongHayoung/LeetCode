/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> res;
    void dfs(Node* n) {
        if(!n) return;
        for(auto c : n->children) dfs(c);
        res.push_back(n->val);
    }
public:
    vector<int> postorder(Node* root) {
        res = {};
        dfs(root);
        return res;
    }
};