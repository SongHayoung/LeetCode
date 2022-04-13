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
    TreeNode* build(vector<int>& order, int& n, int parent) {
        if(n == order.size() || order[n] > parent) return nullptr;
        TreeNode* node = new TreeNode(order[n++]);
        node->left = build(order, n, node->val);
        node->right = build(order, n, parent);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = 0;
        return build(preorder, n, INT_MAX);
    }
};