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
    int maxAncestorDiff(TreeNode* root, int mi = 100000, int ma = 0) {
        return !root ? ma - mi : max(
                maxAncestorDiff(root->left, min(mi, root->val), max(ma, root->val)),
                maxAncestorDiff(root->right, min(mi, root->val), max(ma, root->val))
                );
    }
};