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
    unordered_map<TreeNode*, int> dp[2][2];
    int helper(TreeNode* node, bool watch, bool pWatch) {
        if(!node) return 0;
        if(dp[watch][pWatch].count(node)) return dp[watch][pWatch][node];
        int& res = dp[watch][pWatch][node] = helper(node->left, true, true) + helper(node->right, true, true) + 1;
        if(watch) {
            res = min(res, helper(node->left, false, true) + helper(node->right, false, true));
        } else if(!watch and pWatch) {
            if(node->left and node->right) {
                res = min(res, helper(node->left, false, false) + helper(node->right, false, true));
                res = min(res, helper(node->right, false, false) + helper(node->left, false, true));
            } else if(node->left) {
                res = min(res, helper(node->left, false, false));
            } else if(node->right) {
                res = min(res, helper(node->right, false, false));
            }
        }
        return res;
    }
public:
    int minCameraCover(TreeNode* root) {
        return helper(root, false, true);
    }
};