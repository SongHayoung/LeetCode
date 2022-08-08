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
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> level;
        unordered_map<TreeNode*, TreeNode*> par;
        queue<TreeNode*> q;
        q.push(root);
        par[root] = nullptr;
        level[root] = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* now = q.front(); q.pop();
                if(now->left) {
                    if(level.count(now->left)) {
                        TreeNode* p = par[now];
                        if(p->left == now) p->left = nullptr;
                        if(p->right == now) p->right = nullptr;
                        return root;
                    }
                    level[now->left] = level[now] + 1;
                    par[now->left] = now;
                    q.push(now->left);
                }
                if(now->right) {
                    if(level.count(now->right)) {
                        TreeNode* p = par[now];
                        if(p->left == now) p->left = nullptr;
                        if(p->right == now) p->right = nullptr;
                        return root;
                    }
                    level[now->right] = level[now] + 1;
                    par[now->right] = now;
                    q.push(now->right);
                }
            }
            
        }
        return root;
    }
};