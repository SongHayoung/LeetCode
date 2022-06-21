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
    bool helper(TreeNode* node) {
        if(!node) return false;
        if(!helper(node->left)) node->left = nullptr;
        if(!helper(node->right)) node->right = nullptr;
        return node->left != nullptr or node->right != nullptr or node->val == 1;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return helper(root) ? root : nullptr;
    }
};