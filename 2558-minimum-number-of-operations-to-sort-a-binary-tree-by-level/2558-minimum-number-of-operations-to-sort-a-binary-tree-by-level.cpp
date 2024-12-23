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
    void dfs(TreeNode* node, vector<vector<int>>& nodes, int dep) {
        if(!node) return;
        if(nodes.size() == dep) nodes.emplace_back();
        nodes[dep].push_back(node->val);
        dfs(node->left,nodes,dep + 1);
        dfs(node->right,nodes,dep + 1);
    }
public:
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> nodes;
        dfs(root, nodes, 0);
        int res = 0;
        for(auto& n : nodes) {
            auto s = n;
            sort(begin(s), end(s));
            unordered_map<int, int> mp;
            for(int i = 0; i < n.size(); i++) mp[n[i]] = i;
            for(int i = 0; i < n.size(); i++) {
                if(n[i] == s[i]) continue;
                int p = mp[s[i]];
                swap(n[p],n[i]);
                mp[n[i]] = i;
                mp[n[p]] = p;
                res += 1;
            }
        }
        return res;
    }
};