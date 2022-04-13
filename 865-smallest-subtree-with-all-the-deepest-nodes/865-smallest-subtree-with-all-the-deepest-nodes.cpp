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
    pair<TreeNode*, int> helper(TreeNode* node, int level) {
        if(node->left == nullptr and node->right == nullptr) return {node, level};
        
        if(node->left == nullptr) {
            return helper(node->right, level + 1);
        }
        if(node->right == nullptr) {
            return helper(node->left, level + 1);
        }
        
        auto [leftParent, leftDepth] = helper(node->left, level + 1);
        auto [rightParent, rightDepth] = helper(node->right, level + 1);
        if(leftDepth == rightDepth) return {node, leftDepth};
        if(leftDepth > rightDepth) return {leftParent, leftDepth};
        return {rightParent, rightDepth};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root, 1).first;
    }
};