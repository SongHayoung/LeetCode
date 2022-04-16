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
    int sum = 0;
    void sumHelper(TreeNode* node) {
        if(!node) return;
        sum += node->val;
        sumHelper(node->left);
        sumHelper(node->right);
    }
    void helper(TreeNode* node) {
        if(!node) return;
        helper(node->left);
        int v = node->val;
        node->val = sum;
        sum -= v;
        helper(node->right);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        sumHelper(root);
        helper(root);
        return root;
    }
};