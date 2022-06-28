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
    vector<int> helper(TreeNode* node) {
        if(!node) return {};
        auto res = helper(node->left);
        res.push_back(node->val);
        for(auto& r : helper(node->right))
            res.push_back(r);
        return res;
    }
    TreeNode* helper(vector<int>& A, int l, int r) {
        if(l >= r) return nullptr;
        int ma = max_element(begin(A) + l, begin(A) + r) - begin(A);
        TreeNode* node = new TreeNode(A[ma]);
        node->left = helper(A, l, ma);
        node->right = helper(A, ma + 1, r);
        return node;
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        auto A = helper(root);
        A.push_back(val);
        return helper(A, 0, A.size());
    }
};