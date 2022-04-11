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
    unordered_map<int, pair<unsigned long long,unsigned long long>> m;
    void helper(TreeNode* node, int depth, unsigned long long p) {
        if(!node) return;
        if(!m.count(depth)) {m[depth] = {p,p};}
        m[depth].first = min(m[depth].first, p);
        m[depth].second = max(m[depth].second, p);
        helper(node->left, depth + 1, p * 2);
        helper(node->right, depth + 1, p * 2 + 1);
        
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        helper(root, 0, 0);
        unsigned long long res = 0;
        for(auto [_, p] : m) {
            res = max(res, p.second - p.first + 1);
        }
        return res;
    }
};