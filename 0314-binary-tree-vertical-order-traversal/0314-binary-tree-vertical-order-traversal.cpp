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
    map<int, multimap<int, int>> m;
    void build(TreeNode* node, int order = 0, int depth = 0) {
        if(!node) return;
        m[order].insert({depth, node->val});
        build(node->left, order - 1, depth + 1);
        build(node->right, order + 1, depth + 1);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        build(root);
        vector<vector<int>> res;
        transform(m.begin(), m.end(), back_inserter(res), [](auto const& e) {
            vector<int> _res;
            transform(e.second.begin(), e.second.end(), back_inserter(_res), [](auto const& _e) {return _e.second;});
            return _res; });
        return res;
    }
};
