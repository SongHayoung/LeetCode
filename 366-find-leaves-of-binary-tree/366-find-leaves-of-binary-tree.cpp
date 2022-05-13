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
    vector<vector<int>> res;
    int helper(TreeNode* node) {
        if(!node) return -1;
        int lvl = max(helper(node->left) + 1, helper(node->right) + 1);
        if(res.size() == lvl)
            res.emplace_back();
        res[lvl].push_back(node->val);
        return lvl;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        helper(root);
        return res;
    }
};