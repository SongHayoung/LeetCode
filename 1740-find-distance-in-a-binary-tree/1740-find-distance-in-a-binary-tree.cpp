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
    int res = -1;
    pair<int, bool> helper(TreeNode* node, int p, int q, int level) {
        if(!node or res != -1) return {-1, false};
        if(node->val == p or node->val == q) {
            auto [ll, lf] = helper(node->left, p, q, level + 1);
            auto [rl, rf] = helper(node->right, p, q, level + 1);
            if(lf) {
                res = ll - level;
                return {-1, false};
            } else if(rf) {
                res = rl - level;
                return {-1, false};
            } else return {level, true};
        } else {
            auto [ll, lf] = helper(node->left, p, q, level + 1);
            auto [rl, rf] = helper(node->right, p, q, level + 1);
            if(lf and rf) {
                res = ll + rl - 2 * level;
                return {-1, false};
            } else if(lf) return {ll, lf};
            else if(rf) return {rl, rf};
            return {-1, false};
        }
    }
public:
    int findDistance(TreeNode* root, int p, int q) {
        if(p == q) return 0;
        helper(root, p, q, 0);
        return res;
    }
};