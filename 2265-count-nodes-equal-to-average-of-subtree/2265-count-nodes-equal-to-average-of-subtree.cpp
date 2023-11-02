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
    pair<int, int> helper(TreeNode* node) {
        if(!node) return {0, 0};
        auto [ls, lc] = helper(node->left);
        auto [rs, rc] = helper(node->right);
        auto s = ls + rs + node->val;
        auto c = lc + rc + 1;
        if(s/c == node->val) res++;
        return {s,c};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return res;
    }
};
