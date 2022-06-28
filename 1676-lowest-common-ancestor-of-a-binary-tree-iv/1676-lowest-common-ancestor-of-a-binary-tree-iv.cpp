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
    unordered_map<int, TreeNode*> idmp;
    unordered_map<TreeNode*, int> ridmp;
    int id = 1;
    int LCA[10101][22];
    int level[10101];
    
    void dfs(TreeNode* node, int par, int lvl = 0) {
        if(!node) return;
        int i = id++;
        idmp[i] = node;
        ridmp[node] = i;
        LCA[i][0] = par;
        level[i] = lvl;
        dfs(node->left, i, lvl + 1);
        dfs(node->right, i, lvl + 1);
    }
    void init() {
        for(int i = 0; i < 20; i++) {
            for(int j = 1; j < id; j++) {
                if(LCA[j][i] != -1)
                    LCA[j][i+1] = LCA[LCA[j][i]][i];
            }
        }
    }
    int query(int u, int v) {
        if(level[u] < level[v]) swap(u, v);
        int diff = level[u] - level[v];
        for(int i = 0; diff; i++, diff>>=1) {
            if(diff & 1) u = LCA[u][i];
        }
        if(u != v) {
            for(int i = 21; i >= 0; i--) {
                if(LCA[u][i] != LCA[v][i]) {
                    u = LCA[u][i];
                    v = LCA[v][i];
                }
            }
            u = LCA[u][0];
        }
        return u;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        memset(LCA, -1, sizeof LCA);
        dfs(root, -1);
        init();
        int res = ridmp[nodes.back()]; nodes.pop_back();
        while(!nodes.empty()) {
            res = query(res, ridmp[nodes.back()]);
            nodes.pop_back();
        }
        return idmp[res];
    }
};