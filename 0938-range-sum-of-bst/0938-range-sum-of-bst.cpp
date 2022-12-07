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
    int dnc(TreeNode* root, int mi, int ma, int l, int h) {
        if(!root) return 0;
        if(ma < l or mi > h) return 0;
        int res = 0;
        if(l <= root->val and root->val <= h) res += root->val;
        return res + dnc(root->left, mi, root->val, l, h) + dnc(root->right, root->val, ma, l, h);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return dnc(root, INT_MIN, INT_MAX, low, high);
    }
};