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
    void helper(TreeNode* node, int sum) {
        if(!node) return;
        sum = sum * 10 + node->val;
        if(!node->left and !node->right) {
            res += sum;
        } else {
            helper(node->left, sum);
            helper(node->right, sum);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return res;
    }
};