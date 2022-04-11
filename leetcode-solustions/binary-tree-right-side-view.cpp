/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> res;
    void build(queue<TreeNode*>& q) {
        if(q.empty()) return;
        res.push_back(q.front()->val);
        queue<TreeNode*> nq;
        while(!q.empty()) {
            if(q.front()->right != nullptr) nq.push(q.front()->right);
            if(q.front()->left != nullptr) nq.push(q.front()->left);
            q.pop();
        }
        build(nq);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        build(q);
        
        return res;
    }
};
