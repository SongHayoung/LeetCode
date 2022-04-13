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
    int res = 0;
    pair<bool, int> helper(TreeNode* node, int mi, int ma) {
        if(!node) return {true, 0};
        res = max(res, 1);
        if(mi < node->val and node->val < ma) {
            auto [lbst, lsub] = helper(node->left, mi, node->val);
            auto [rbst, rsub] = helper(node->right, node->val, ma);
           
            if(lbst and rbst) {
                res = max(res, lsub + rsub + 1);
                return {true, lsub + rsub + 1};
            } else {
                auto [lbst, lsub] = helper(node->left, INT_MIN, node->val);
                auto [rbst, rsub] = helper(node->right, node->val, INT_MAX);
                if(lbst and rbst) {
                    res = max(res,lsub + rsub + 1);
                }
                return {false, 0};
            }
        } else {
            auto [lbst, lsub] = helper(node->left, INT_MIN, node->val);
            auto [rbst, rsub] = helper(node->right, node->val, INT_MAX);
            if(lbst and rbst) {
                res = max(res,lsub + rsub + 1);
            }
            return {false, 0};
        }
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        helper(root, INT_MIN, INT_MAX);
        return res;
    }
};