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
    int minimumLevel(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        long long res = 0, sum = LLONG_MAX, lvl = 1;
        while(q.size()) {
            int qsz = q.size();
            long long now = 0;
            while(qsz--) {
                auto n = q.front(); q.pop();
                now += n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            if(now < sum) {
                res = lvl;
                sum = now;
            }
            lvl++;
        }
        return res;
    }
};