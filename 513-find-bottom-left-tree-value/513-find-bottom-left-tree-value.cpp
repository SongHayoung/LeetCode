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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int res;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            res = q.front()->val;
            while(sz--) {
                auto u = q.front(); q.pop();
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
        }
        return res;
    }
};