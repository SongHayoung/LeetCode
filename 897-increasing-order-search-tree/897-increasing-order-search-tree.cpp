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
    vector<TreeNode*> A;
    void helper(TreeNode* node) {
        if(!node) return;
        helper(node->left);
        A.push_back(node);
        helper(node->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        helper(root);
        for(int i = 0; i < A.size() - 1; i++) {
            A[i]->left = nullptr;
            A[i]->right = A[i+1];
        }
        A.back()->left = nullptr;
        return A[0];
    }
};