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
    unordered_map<int, vector<TreeNode*>> dp;
    vector<TreeNode*> helper(int mi, int ma) {
        if(dp.count(mi * 10 + ma)) return dp[mi * 10 + ma];
        if(mi > ma) return {nullptr};
        vector<TreeNode*> res;
        for(int root = mi; root <= ma; root++) {
            auto left = helper(mi, root - 1);
            auto right = helper(root + 1, ma);
            for(auto& l : left) {
                for(auto& r : right) {
                    TreeNode* node = new TreeNode(root, l, r);
                    res.push_back(node);
                }
            }
        }
        return dp[mi * 10 + ma] = res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};