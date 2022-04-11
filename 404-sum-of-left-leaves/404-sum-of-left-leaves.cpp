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
    int sum = 0;
    void helper(TreeNode* node, bool left) {
        if(!node) return;
        if(left) {
            if(!node->left and !node->right)
                sum += node->val;
        }
        helper(node->left, true);
        helper(node->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root,false);
        return sum;
    }
};