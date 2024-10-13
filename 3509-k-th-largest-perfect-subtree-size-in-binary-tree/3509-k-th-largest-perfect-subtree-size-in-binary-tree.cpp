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
    vector<int> res;
    pair<int,int> dfs(TreeNode* node) {
        if(!node) return {0,0};
        if(!node->left and !node->right) {
            res.push_back(1);
            return {1,1};
        }
        auto [lok, lc] = dfs(node->left);
        auto [rok, rc] = dfs(node->right);
        if(lok and rok and lc == rc) {
            res.push_back(lc + rc + 1);
            return {1,lc + rc + 1};
        }
        return {0,0};
    }
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        res = {};
        dfs(root);
        sort(rbegin(res), rend(res));
        if(res.size() < k) return -1;
        return res[k-1];
    }
};