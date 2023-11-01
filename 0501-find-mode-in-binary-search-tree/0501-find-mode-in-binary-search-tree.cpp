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
    void dfs(TreeNode* t, unordered_map<int,int>& f) {
        if(!t) return;
        f[t->val] += 1;
        dfs(t->left,f);
        dfs(t->right,f);
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        dfs(root,freq);
        vector<int> res;
        int ma = -1;
        for(auto& [_,v] : freq) ma = max(ma, v);
        for(auto& [k,v] : freq) if(v == ma) res.push_back(k);
        return res;
    }
};