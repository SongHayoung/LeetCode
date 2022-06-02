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
    vector<vector<int>> res;
    void helper(TreeNode* node, int level = 0) {
        if(!node) return;
        if(res.size() <= level) res.emplace_back();
        res[level].push_back(node->val);
        helper(node->left, level + 1);
        helper(node->right, level + 1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        helper(root);
        
        reverse(begin(res), end(res));
        return res;
    }
};