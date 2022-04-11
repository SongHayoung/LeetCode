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
    double diff = DBL_MAX;
    int res = 0;
    void helper(TreeNode* n, double t) {
        if(!n) return;
        if(abs(n->val - t) < diff) {
            diff = abs(n->val - t);
            res = n->val;
        }
        helper(n->left,t);
        helper(n->right,t);
    }
public:
    int closestValue(TreeNode* root, double target) {
        helper(root,target);
        return res;
    }
};