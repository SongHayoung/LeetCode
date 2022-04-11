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
    vector<int> preorder(Node* root) {
        vector<int> res;
        vector<Node*> st;
        if(root) st.push_back(root);
        while(!st.empty()) {
            auto n = st.back(); st.pop_back();
            res.push_back(n->val);
            for(int i = n->children.size() - 1; i>= 0; i--)
                st.push_back(n->children[i]);
        }

        return res;
    }
};