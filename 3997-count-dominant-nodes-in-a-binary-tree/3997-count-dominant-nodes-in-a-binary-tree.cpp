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
    int dfs(TreeNode* root, int& res) {
        if(!root) return INT_MIN;
        int ma = max(dfs(root->left, res), dfs(root->right, res));
        if(root->val >= ma) res++;
        return max(ma, root->val);
    }
public:
    int countDominantNodes(TreeNode* root) {
        int res = 0;
        dfs(root,res);
        return res;
    }
};