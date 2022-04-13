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
    vector<TreeNode *> splitBST(TreeNode *root, int target) {
        vector<TreeNode *> res(2,NULL);
        if(!root) return res;
        if(root->val > target) {
            res[1] = root;
            auto child = splitBST(root->left, target);
            root->left = child[1];
            res[0] = child[0];
        } else {
            res[0] = root;
            auto child = splitBST(root->right, target);
            root->right = child[0];
            res[1] = child[1];
        }
        return res;
    }
};