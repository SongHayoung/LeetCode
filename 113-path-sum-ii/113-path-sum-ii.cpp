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
    void helper(TreeNode* node, int target, vector<int>& A) {
        if(!node->left and !node->right) {
            if(target == node->val) {
                res.push_back(A);
                res.back().push_back(target);
            }
            return;
        }
        
        target -= node->val;
        A.push_back(node->val);
        
        if(node->left)
            helper(node->left, target, A);
        if(node->right)
            helper(node->right, target, A);
        
        A.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return res;
        helper(root, targetSum, vector<int>() = {});
        return res;
    }
};