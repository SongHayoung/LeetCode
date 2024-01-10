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
    unordered_map<int, vector<int>> adj;
    unordered_set<int> vis;
    void dfs(TreeNode* node) {
        if(!node) return;
        int v = node->val;
        if(node->left) {
            adj[v].push_back(node->left->val);
            adj[node->left->val].push_back(v);
            dfs(node->left);
        }
        if(node->right) {
            adj[v].push_back(node->right->val);
            adj[node->right->val].push_back(v);
            dfs(node->right);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        queue<int> q;
        q.push(start);
        vis.insert(start);
        int res = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int u = q.front(); q.pop();
                for(auto& v : adj[u]) {
                    if(!vis.count(v)) {
                        vis.insert(v);
                        q.push(v);
                    }
                }
            }
            res++;
        }
        return res - 1;
    }
};