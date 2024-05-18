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
    unordered_map<TreeNode*, int> c,n;
    void dfs1(TreeNode* t) {
        c[t] = t->val;
        n[t] = 1;
        if(t->left) {
            dfs1(t->left);
            c[t] += c[t->left];
            n[t] += n[t->left];
        }
        if(t->right) {
            dfs1(t->right);
            c[t] += c[t->right];
            n[t] += n[t->right];
        }
    }
    int dfs2(TreeNode* t, int x) {
        t->val += x;
        int res = 0;
        if(t->left) {
            auto lt = t->left;
            if(c[lt] > n[lt]) {
                res += dfs2(lt,0);
                t->val += c[lt] - n[lt];
            }
        }
        if(t->right) {
            auto rt = t->right;
            if(c[rt] > n[rt]) {
                res += dfs2(rt,0);
                t->val += c[rt] - n[rt];
            }
        }
        if(t->left) {
            auto lt = t->left;
            if(c[lt] <= n[lt]) {
                int req = n[lt] - c[lt];
                res += req;
                t->val -= req;
                res += dfs2(lt,req);
            }
        }
        if(t->right) {
            auto rt = t->right;
            if(c[rt] <= n[rt]) {
                int req = n[rt] - c[rt];
                res += req;
                t->val -= req;
                res += dfs2(rt,req);
            }
        }
        
        return res + (t->val - 1);
    }
public:
    int distributeCoins(TreeNode* root) {
        c = n = {};
        dfs1(root);
        return dfs2(root,0);
    }
};