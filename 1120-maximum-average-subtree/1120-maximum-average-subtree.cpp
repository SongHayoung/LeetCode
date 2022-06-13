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
    double avg = 0;
    pair<int, int> helper(TreeNode* node) {
        if(!node) return {0, 0};
        auto [ls, lc] = helper(node->left);
        auto [rs, rc] = helper(node->right);
        pair<int, int> res {ls + rs + node->val, lc + rc + 1};
        avg = max(avg, 1.0 * res.first / res.second);
        return res;
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        helper(root);
        return avg;
    }
};