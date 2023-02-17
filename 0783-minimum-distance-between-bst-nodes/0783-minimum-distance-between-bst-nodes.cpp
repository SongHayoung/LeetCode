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
    void dfs(TreeNode* node, vector<int>& vals) {
        if(!node) return;
        vals.push_back(node->val);
        dfs(node->left, vals);
        dfs(node->right, vals);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        vector<int> vals;
        dfs(root,vals);
        sort(begin(vals), end(vals));
        for(int i = 0; i < vals.size() - 1; i++) {
            res = min(res, abs(vals[i] - vals[i+1]));
        }
        return res;
    }
};