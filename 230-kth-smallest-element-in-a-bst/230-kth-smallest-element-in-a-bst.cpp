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
    void postOrder(TreeNode* node, int& k, int& res){
        if(!node) return;
        postOrder(node->left, k, res);
        if(res != -1) return;
        if(--k == 0) {res = node->val; return;}
        postOrder(node->right, k, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        postOrder(root, k, res);
        return res;
    }
};