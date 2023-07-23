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
    vector<TreeNode*> dp[21];
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(!dp[n].empty()) return dp[n];
        if(n == 1) return dp[1] = vector<TreeNode*>{new TreeNode()};
        for(int i = 1; i <= n - 2; i++) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-1-i);
            for(auto& l : left) {
                for(auto& r : right) {
                    dp[n].push_back(new TreeNode(0,l,r));
                }
            }
        }
        return dp[n];
    }
};