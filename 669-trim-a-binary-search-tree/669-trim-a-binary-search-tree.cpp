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
    TreeNode* helper(TreeNode* node, int& l, int& r) {
        if(!node) return nullptr;
        if(l <= node->val and node->val <= r) {
            node->left = helper(node->left, l, r);
            node->right = helper(node->right, l, r);
            return node;
        } else if(l > node->val) return helper(node->right, l, r);
        else return helper(node->left, l, r);
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return helper(root, low, high);
    }
};