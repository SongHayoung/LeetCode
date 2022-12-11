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
    int res = INT_MIN;
    int helper(TreeNode* node) {
        if(!node) return 0;
        int leftSum = helper(node->left);
        int rightSum = helper(node->right);
        
        int innerSum = max({node->val + leftSum, node->val + rightSum, node->val + leftSum + rightSum, node->val});
        res = max(res, innerSum);
        int pathSum = max({node->val, leftSum + node->val, rightSum + node->val});
        return pathSum;
    }
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return res;
    }
};