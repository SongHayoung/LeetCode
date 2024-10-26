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
    unordered_map<int, int> lvl;
    unordered_map<int, int> at;
    unordered_map<int, vector<int>> best;
    int dfs(TreeNode* node, int dep = 0) {
        if(!node) return 0;
        int d = max({dep, dfs(node->left, dep + 1), dfs(node->right, dep + 1)});
        at[node->val] = dep;
        lvl[node->val] = d;
        best[dep].push_back(node->val);
        sort(begin(best[dep]), end(best[dep]), [&](int i, int j) {
            return lvl[i] > lvl[j];
        });
        if(best[dep].size() > 2) best[dep].pop_back();
        return d;
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root);
        vector<int> res;
        for(auto& q : queries) {
            int now = at[q] - 1;
            for(auto& x : best[at[q]]) {
                if(x == q) continue;
                now = max(now, lvl[x]);
            }
            res.push_back(now);
        }
        return res;
    }
};