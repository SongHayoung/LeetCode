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
    void dfs1(TreeNode* node, int dep, vector<long long>& sum) {
        if(sum.size() == dep) sum.push_back(0);
        sum[dep] += node->val;
        if(node->left) dfs1(node->left,dep+1,sum);
        if(node->right) dfs1(node->right,dep+1,sum);
    }
    void dfs2(TreeNode* node, int dep, vector<long long>& sum, int now) {
        node->val = sum[dep] - now;
        int sub = 0;
        if(node->left) sub += node->left->val;
        if(node->right) sub += node->right->val;
        if(node->left) dfs2(node->left,dep+1,sum,sub);
        if(node->right) dfs2(node->right,dep+1,sum,sub);
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<long long> sum;
        dfs1(root,0,sum);
        dfs2(root,0,sum,root->val);
        return root;
    }
};