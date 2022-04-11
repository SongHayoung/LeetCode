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
    bool res = false;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return healper(root, targetSum);
    }
    
    bool healper(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left and !root->right) {
            if(targetSum == root->val) res = true;
            return res;
        }
        healper(root->left, targetSum - root->val);
        healper(root->right, targetSum - root->val);
        return res;
    }
};