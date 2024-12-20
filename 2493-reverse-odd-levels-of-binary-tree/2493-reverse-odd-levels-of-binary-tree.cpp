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
    unordered_map<int, vector<TreeNode*>> mp;
    void dfs(TreeNode* node, int level) {
        if(!node) return;
        mp[level].push_back(node);
        dfs(node->left,level+1);
        dfs(node->right,level+1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root,0);
        int l = 1;
        while(mp.count(l)) {
            vector<TreeNode*>& vec = mp[l];
            int lo = 0, hi = vec.size() - 1;
            while(lo < hi) {
                swap(vec[lo]->val,vec[hi]->val);
                lo++,hi--;
            }
            l += 2;
        }
        return root;
    }
};