/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return NULL;
        if(root->val == p->val + 1) return root;
        if(root->val < p->val + 1) return inorderSuccessor(root->right, p);
        TreeNode* res = inorderSuccessor(root->left, p);
        if(!res) res = root;
        return res;
    }
};