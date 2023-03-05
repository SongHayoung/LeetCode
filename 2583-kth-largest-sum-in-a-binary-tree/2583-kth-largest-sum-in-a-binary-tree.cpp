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
    unordered_map<int, long long> sum;
    void dfs(TreeNode* node, int level) {
        if(!node) return;
        sum[level] += node->val;
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root,0);
        if(sum.size() < k) return -1;
        vector<long long> S;
        for(auto [k,v] : sum) S.push_back(v);
        sort(rbegin(S), rend(S));
        return S[k-1];
    }
};
