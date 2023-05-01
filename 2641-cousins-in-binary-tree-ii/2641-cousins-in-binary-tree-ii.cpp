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
    unordered_map<TreeNode*, int> sum;
    unordered_map<int, int> lsum;
    void dfs1(TreeNode* node, int dep) {
        lsum[dep] += node->val;
        int now = 0;
        if(node->left) now += node->left->val;
        if(node->right) now += node->right->val;
        if(node->left) {
            sum[node->left] = now;
            dfs1(node->left, dep + 1);
        }
        if(node->right) {
            sum[node->right] = now;
            dfs1(node->right, dep + 1);
        }
    }
    void dfs2(TreeNode* node, int dep) {
        node->val = lsum[dep] - sum[node];
        if(node->left) dfs2(node->left, dep + 1);
        if(node->right) dfs2(node->right, dep + 1);
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs1(root,0);
        dfs2(root,0);
        root->val = 0;
        return root;
    }
};
