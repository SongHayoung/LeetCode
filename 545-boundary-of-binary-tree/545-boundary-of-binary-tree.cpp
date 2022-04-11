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
    vector<int> res;
    bool isLeaf(TreeNode* node) {
        if(!node) return false;
        return !node->right && !node->left;
    }
    void pushLeft(TreeNode* node) {
        if(!node) return;
        res.push_back(node->val);
        if(node->left) {
            pushLeft(node->left);
            pushLeaf(node->right);
        } else pushLeft(node->right);
    }
    void pushRight(TreeNode* node) {
        if(!node) return;
        if(node->right) {
            pushLeaf(node->left);
            pushRight(node->right);
        } else pushRight(node->left);
        res.push_back(node->val);
    }
    void pushLeaf(TreeNode* node) {
        if(!node) return;
        if(isLeaf(node)) {
            res.push_back(node->val);
        } else {
            pushLeaf(node->left);
            pushLeaf(node->right);
        }
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        res.push_back(root->val);
        pushLeft(root->left);
        pushRight(root->right);

        return res;
    }
};