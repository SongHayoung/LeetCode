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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key == root->val) {
            TreeNode *l = root->left, *r = root->right;
            if(!l and !r) return nullptr;
            if(l and r) {
                TreeNode* res = r;
                while(r->left) r = r->left;
                r->left = l;
                return res;
            } else if(l) return l;
            else return r;
        } else {
            if(root->val > key) root->left = deleteNode(root->left, key);
            else root->right = deleteNode(root->right, key);
            return root;
        }
    }
};