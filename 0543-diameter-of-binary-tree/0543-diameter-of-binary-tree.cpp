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
    int dfs(TreeNode* node, int& res, int dep) {
        int now = 0, ma = dep;
        if(node->left) {
            int x = dfs(node->left, res, dep + 1);
            now += x - dep;
            ma = max(ma, x);
        }
        if(node->right) {
            int x = dfs(node->right, res, dep + 1);
            now += x - dep;
            ma = max(ma, x);
        }
        res = max(res, now);
        return ma;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        res = max(res, dfs(root, res, 0));
        return res;
    }
};
