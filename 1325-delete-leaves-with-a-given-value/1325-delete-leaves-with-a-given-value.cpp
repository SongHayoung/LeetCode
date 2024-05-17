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
    TreeNode* dfs(TreeNode* n, int t) {
        if(n->left) n->left = dfs(n->left,t);
        if(n->right) n->right = dfs(n->right,t);
        if(!n->left and !n->right and n->val == t) return nullptr;
        return n;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root,target);
    }
};