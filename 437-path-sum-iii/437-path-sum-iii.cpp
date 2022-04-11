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
    void solution(TreeNode* node, int &t, int& res, unordered_map<long,int>& prev, long sum) {
        if(!node) return;
        sum += node->val;
        
        res += prev[sum - t];
        
        prev[sum]++;
        solution(node->left, t, res, prev, sum);
        solution(node->right, t, res, prev, sum);
        prev[sum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        unordered_map<long,int> prev{{0,1}};
        solution(root, targetSum, res, prev, 0);
        return res;
    }
};