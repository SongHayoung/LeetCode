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
    TreeNode* helper(TreeNode* node, int key) {
        if(!node) return nullptr;
        if(key == node->val) {
            TreeNode *l = node->left, *r = node->right;
            if(!l and !r) return nullptr;
            if(l and r) {
                TreeNode* res = r;
                while(r->left) r = r->left;
                r->left = l;
                return res;
            } else if(l) return l;
            else return r;
        } else {
            if(node->val > key) node->left = helper(node->left, key);
            else node->right = helper(node->right, key);
            return node;
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return helper(root, key);
    }
};