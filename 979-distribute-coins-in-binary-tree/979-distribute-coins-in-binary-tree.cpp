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
    int res = 0;
    int dfs(TreeNode* node) {
        if(!node) return 0;
        int l = dfs(node->left), r = dfs(node->right);
        res += abs(l) + abs(r);
        return node->val + l + r - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
};