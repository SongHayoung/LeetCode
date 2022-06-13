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
    unordered_map<int, int> freq;
    int helper(TreeNode* node) {
        if(!node) return 0;
        int res = helper(node->left) + helper(node->right) + node->val;
        freq[res]++;
        return res;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        vector<int> res;
        for(auto& [k, v] : freq) {
            if(res.empty()) res.push_back(k);
            else if(freq[res[0]] == v) res.push_back(k);
            else if(freq[res[0]] > v) continue;
            else {
                res.clear();
                res.push_back(k);
            }
        }
        return res;
    }
};