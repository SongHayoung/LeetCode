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
    unordered_map<int, int> freq;

    void dfs1(TreeNode* u) {
        if(++freq[u->val] > 3) return;
        if(u->left) dfs1(u->left);
        if(u->right) dfs1(u->right);
    }
    void dfs2(TreeNode* u, int& res, int dep = 0) {
        res = max(res, dep);
        if(freq[u->val] == 1) {
            if(u->left) dfs2(u->left,res,dep+1);
            if(u->right) dfs2(u->right,res,dep+1);
        }
    }
public:
    int heightOfTree(TreeNode* root) {
        freq = {};
        int res = 0;
        dfs1(root);
        dfs2(root,res);
        return res;
    }
};