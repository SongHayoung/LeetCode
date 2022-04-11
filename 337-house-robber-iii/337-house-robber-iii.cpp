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
    pair<int,int> helper(TreeNode* node) {
        if(!node) return {0,0};
        auto [lrob, lpass] = helper(node->left);
        auto [rrob, rpass] = helper(node->right);
        
        return {lpass + rpass, max(lrob + rrob + node->val, lpass + rpass)};
    }
public:
    int rob(TreeNode* root) {
        auto [res1, res2] = helper(root);
        return max(res1, res2);
    }
};