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
    bool find(TreeNode* node, int val) {
        if(!node) return false;
        if(node->val == val) return true;
        if(node->val < val) return find(node->right, val);
        return find(node->left, val);
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(!root1) return false;
        if(find(root2, target - root1->val)) return true;
        
        return twoSumBSTs(root1->left, root2, target) or twoSumBSTs(root1->right, root2, target);
    }
};