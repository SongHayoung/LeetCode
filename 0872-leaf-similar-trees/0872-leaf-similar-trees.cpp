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
    void dfs(TreeNode* node, vector<int>& A) {
        if(!node) return;
        if(!node->left and !node->right) {
            A.push_back(node->val);
        }
        dfs(node->left,A);
        dfs(node->right,A);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> A,B;
        dfs(root1,A);
        dfs(root2,B);
        return A == B;
    }
};