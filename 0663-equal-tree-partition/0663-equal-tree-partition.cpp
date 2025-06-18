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
    int dfs(TreeNode* node) {
        if(!node) return 0;
        return node->val + dfs(node->left) + dfs(node->right);
    }
    int dfs2(TreeNode* node, int& total) {
        if(!node) return 0;
        int sum = node->val + dfs2(node->left, total) + dfs2(node->right, total);
        if(sum * 2 == total) res = true;
        return sum;
    }
public:
    bool checkEqualTree(TreeNode* root) {
        int total = dfs(root);
        dfs2(root->left, total);
        dfs2(root->right, total);
        return res;
    }
};