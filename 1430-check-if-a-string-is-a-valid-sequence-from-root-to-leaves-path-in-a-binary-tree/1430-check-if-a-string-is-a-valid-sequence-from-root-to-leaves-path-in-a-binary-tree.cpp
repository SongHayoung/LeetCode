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
    bool helper(TreeNode* node, vector<int>& A, int pos) {
        if(pos == A.size() or node == nullptr or node->val != A[pos]) return false;
        if(pos == A.size() - 1 and node->left == nullptr and node->right == nullptr) return true;
        return helper(node->left, A, pos + 1) or helper(node->right, A, pos + 1);
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return helper(root, arr, 0);
    }
};