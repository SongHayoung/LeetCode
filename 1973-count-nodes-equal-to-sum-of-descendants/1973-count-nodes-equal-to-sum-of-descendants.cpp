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
    long long helper(TreeNode* node) {
        if(!node) return 0;
        long long sum = helper(node->left) + helper(node->right);
        if(sum == node->val) res++;
        return sum + node->val;
    }
public:
    int equalToDescendants(TreeNode* root) {
        helper(root);
        return res;
    }
};