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
    bool recursive(TreeNode* node, long min, long max) {
        bool ret = true;
        if(node->left != nullptr) {
            if(node->val > node->left->val && node->left->val > min)
                ret &= recursive(node->left, min, node->val);
            else
                return false;
        }
        if(ret && node->right != nullptr){
            if(node->val < node->right->val && node->right->val < max)
                ret &= recursive(node->right, node->val, max);
            else
                return false;
        }

        return ret;
    }
public:
    bool isValidBST(TreeNode* root) {
        return recursive(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
};
