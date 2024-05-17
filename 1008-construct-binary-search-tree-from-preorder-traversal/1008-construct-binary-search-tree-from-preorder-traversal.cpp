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
    TreeNode* dfs(vector<int>& A, int l, int r) {
        if(l > r) return nullptr;
        TreeNode* res = new TreeNode(A[l]);
        int p = l + 1;
        while(p <= r and A[p] < A[l]) p++;
        res->left = dfs(A,l+1,p-1);
        res->right = dfs(A,p,r);
        return res;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder,0,preorder.size() - 1);
    }
};