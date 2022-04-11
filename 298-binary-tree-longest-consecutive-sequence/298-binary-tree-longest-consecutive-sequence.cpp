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
public:
    int longestConsecutive(TreeNode* root, int seq = 1) {
        if(!root) return 0;
        int res = seq;
        if(root->left) {
            int diff = root->left->val - root->val;
            if(diff != 1) {
                res = max(res, longestConsecutive(root->left, 1));
            } else {
                res = max(res, longestConsecutive(root->left, seq + 1));
            }
        }
        
        if(root->right) {
            int diff = root->right->val - root->val;
            if(diff != 1) {
                res = max(res, longestConsecutive(root->right, 1));
            } else {
                res = max(res, longestConsecutive(root->right, seq + 1));
            }
        }
        
        return res;
    }
};