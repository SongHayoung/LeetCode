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
    map<int, map<int, vector<int>>> order;
    void travel(TreeNode* node, int r, int c) {
        if(!node) return;
        order[c][r].push_back(node->val);
        travel(node->left, r + 1, c - 1);
        travel(node->right, r + 1, c + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        travel(root, 0, 0);
        for(auto [c, rowMap]: order) {
            vector<int> ans;
            for(auto [r, vec] : rowMap) {
                sort(vec.begin(),vec.end());
                ans.insert(ans.end(), vec.begin(), vec.end());
            }
            res.push_back(ans);
        }
        return res;
    }
};