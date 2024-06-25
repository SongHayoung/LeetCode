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
    TreeNode* helper(TreeNode* node, int& sum) {
        if(!node) return nullptr;
        helper(node->right, sum);
        node->val = (sum += node->val);
        helper(node->left, sum);
        return node;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        return helper(root, sum);
    }
};
