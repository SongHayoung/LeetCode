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
    int ans = 0;
    bool eq(TreeNode* root) {
        if(!root) return false;
        else if(!root->left and !root->right) {
            ans++;
            return true;
        } else if(root->left and root->right) {
            bool res = true;
            res &= eq(root->left);
            res &= eq(root->right);
            if(!res) return false;
            if(root->val == root->left->val and root->val == root->right->val) {
                ans++;
                return true;
            }
            return false;
        } else if(root->left) {
            bool res = eq(root->left);
            if(!res) return false;
            if(res && root->left->val == root->val) {
                ans++;
                return true;
            }
            return false;
        } else {
            bool res = eq(root->right);
            if(!res) return false;
            if(res && root->right->val == root->val) {
                ans++;
                return true;
            }
            return false;
        }
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        eq(root);
        return ans;
    }
};