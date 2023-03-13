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
    bool solution(TreeNode* l, TreeNode* r) {
        if(!l and !r) return true;
        if((!l and r) or (!r and l) or (l->val != r->val)) return false;
        return solution(l->left, r->right) and solution(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solution(root->left, root->right);
    }
};