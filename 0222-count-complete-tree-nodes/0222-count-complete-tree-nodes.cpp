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
    int res = 0;
public:
    int countNodes(TreeNode* root, int level = 0, int front = 0) {
        if(!root) return 0;
        if(root->right or root->left) {
            countNodes(root->right, level + 1, front * 2 + 1);
            countNodes(root->left, level + 1, front * 2);
        } else {
            int prev = 0;
            for(int i = 0; i < level; i++) {
                prev += (1<<i);
            }
            res = max(res, front + 1 + prev);
        }
        return res;
    }
};