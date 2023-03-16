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
    unordered_map<int, int> rin;
    TreeNode* helper(vector<int>& in, vector<int>& post, int il, int ir, int pl, int pr) {
        if(il > ir or pl > pr) return nullptr;
        TreeNode* root = new TreeNode(post[pr]);
        
        root->left = helper(in, post, il, rin[post[pr]] - 1, pl, pl + rin[post[pr]] -1 - il);
        root->right = helper(in, post, rin[post[pr]] + 1, ir, pl + rin[post[pr]] - il, pr - 1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++) rin[inorder[i]] = i;

        return helper(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};