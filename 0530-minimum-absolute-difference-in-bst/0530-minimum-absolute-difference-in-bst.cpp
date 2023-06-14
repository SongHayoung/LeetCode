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
    void dfs(TreeNode* node, vector<int>& A) {
        A.push_back(node->val);
        if(node->left) {
            dfs(node->left, A);
        }
        if(node->right) {
            dfs(node->right, A);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        vector<int> A;
        dfs(root,A);
        sort(begin(A), end(A));
        for(int i = 0; i < A.size() - 1; i++) res = min(res, A[i+1] - A[i]);
        return res;
    }
};