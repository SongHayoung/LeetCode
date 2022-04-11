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
    int search(TreeNode* node, int X) {
        int res = node->val >= X;
        if(node->left != nullptr) {
            res += search(node->left, max(X, node->val));
        }
        if(node->right != nullptr) {
            res += search(node->right, max(X, node->val));
        }

        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        return search(root, root->val);
    }
};
