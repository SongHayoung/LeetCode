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
public:
    bool isEvenOddTree(TreeNode* root) {
        int dep = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int qsz = q.size(), x = dep & 1 ? INT_MAX : INT_MIN;
            while(qsz--) {
                auto u = q.front(); q.pop();
                if(dep & 1) {
                    if(x <= u->val) return false;
                    if(u->val & 1) return false;
                } else {
                    if(x >= u->val) return false;
                    if(u->val % 2 == 0) return false;
                }
                x = u->val;
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            dep++;
        }
        return true;
    }
};