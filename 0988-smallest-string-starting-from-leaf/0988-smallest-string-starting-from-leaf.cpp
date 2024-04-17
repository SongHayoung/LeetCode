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
    void dfs(TreeNode* node, string& res, string& s) {
        if(!node) return;
        s.push_back(node->val + 'a');
        if(!node->left and !node->right) {
            string rev = s;
            reverse(begin(rev), end(rev));
            res = min(res, rev);
        } else {
            dfs(node->left, res, s);
            dfs(node->right, res, s);
        }
        
        s.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string res = string(1,'z' + 1), s = "";
        dfs(root,res,s);
        return res;
    }
};