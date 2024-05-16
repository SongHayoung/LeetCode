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
    long long dfs(TreeNode* n, int& res) {
        if(!n) return 0;
        long long sub = dfs(n->left, res) + dfs(n->right, res);
        if(sub == n->val) res++;
        return sub + n->val;
    }
public:
    int equalToDescendants(TreeNode* root) {
        int res = 0;
        dfs(root,res);
        return res;
    }
};