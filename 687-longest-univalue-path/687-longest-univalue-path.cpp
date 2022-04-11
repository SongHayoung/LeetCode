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
    int path(TreeNode* root) {
        int left(0), right(0);
        if(root->left) {
            if(root->left->val == root->val) {
                left = path(root->left);
            } else {
                path(root->left);
            }
        }

        if(root->right) {
            if(root->right->val == root->val) {
                right = path(root->right);
            } else {
                path(root->right);
            }
        }
        res = max(res, left + right);
        return max(left, right) + 1;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        path(root);
        return res;
    }
};