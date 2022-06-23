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
    unordered_map<int, pair<int, int>> mp;
    pair<int, int> dfs(TreeNode* node) {
        if(!node->left and !node->right) {
            mp[node->val] = {0, node->val};
            return {1, node->val};
        }
        mp[node->val] = {INT_MAX, INT_MAX};
        if(node->left) {
            auto [d, v] = dfs(node->left);
            if(mp[node->val].first > d) mp[node->val] = {d, v};
        }
        if(node->right) {
            auto [d, v] = dfs(node->right);
            if(mp[node->val].first > d) mp[node->val] = {d, v};
        }
        
        return {mp[node->val].first + 1, mp[node->val].second};
    }
    void dfs2(TreeNode* node, int par) {
        if(!node) return;
        auto v = node->val;
        if(mp[v].first > mp[par].first + 1) {
            mp[v] = mp[par];
            mp[v].first++;
        }
        dfs2(node->left, v);
        dfs2(node->right, v);
    }
public:
    int findClosestLeaf(TreeNode* root, int k) {
        mp[-1] = {INT_MAX - 1, INT_MAX - 1};
        dfs(root);
        dfs2(root, -1);
        return mp[k].second;
    }
};