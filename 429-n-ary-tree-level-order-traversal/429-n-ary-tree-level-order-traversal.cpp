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
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> cur;
            int sz = q.size();
            while(sz--) {
                auto n = q.front();
                q.pop();
                cur.push_back(n->val);
                for(auto& c : n->children) {
                    q.push(c);
                }
            }
            res.push_back(cur);
        }
        
        return res;
    }
};