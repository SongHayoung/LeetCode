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
    vector<vector<int>> res;
    void dfs(TreeNode* n, int x, vector<int>& p) {
        if(!n) return;
        p.push_back(n->val);
        x -= n->val;
        if(x == 0 and !n->left and !n->right) res.push_back(p);
        dfs(n->left,x,p);
        dfs(n->right,x,p);
        p.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        res = {};
        dfs(root,targetSum,path);
        return res;
    }
};