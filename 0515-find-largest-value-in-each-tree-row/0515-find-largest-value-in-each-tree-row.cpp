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
    vector<int> res;
    void helper(TreeNode* node, int level) {
        if(!node) return;
        if(res.size() == level) res.push_back(node->val);
        res[level] = max(res[level], node->val);
        helper(node->left, level + 1);
        helper(node->right, level + 1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        helper(root, 0);
        return res;
    }
};