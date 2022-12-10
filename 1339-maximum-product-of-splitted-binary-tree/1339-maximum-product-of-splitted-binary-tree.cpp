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
    unordered_map<TreeNode*, int> m;
    int getSum(TreeNode* node) {
        if(!node) return 0;
        return m[node] = getSum(node->left) + getSum(node->right) + node->val;
    }
public:
    int maxProduct(TreeNode* root) {
        long long res = 0, mod = 1e9 + 7;
        long long total = getSum(root);
        for(auto& [k, v]: m) {
            res = max(res, (total - v) * v);
        }
        return res % mod;
    }
};
