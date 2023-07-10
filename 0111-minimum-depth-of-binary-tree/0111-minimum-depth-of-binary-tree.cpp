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
    void dfs(TreeNode* node, int& res, int dep) {
        if(!node->left and !node->right) res = min(res, dep);
        else {
            if(node->left) dfs(node->left, res, dep + 1);
            if(node->right) dfs(node->right, res, dep + 1);
        }
    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int res = INT_MAX;
        dfs(root, res, 1);
        return res;
    }
};