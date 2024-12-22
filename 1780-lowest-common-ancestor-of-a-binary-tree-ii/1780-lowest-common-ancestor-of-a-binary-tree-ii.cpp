/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* res = nullptr;
    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node) return false;
        if(res) return false;
        if(node == p or node == q) {
            if(dfs(node->left, p, q) or dfs(node->right, p, q)) {
                res = node;
                return false;
            }
            return true;
        }
        auto l = dfs(node->left, p, q), r = dfs(node->right, p, q);
        if(l and r) {
            res = node;
            return false;
        }
        return l or r;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
};