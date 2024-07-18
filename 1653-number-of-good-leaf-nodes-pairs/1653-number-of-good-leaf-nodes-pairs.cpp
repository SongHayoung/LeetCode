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
    int sum = 0;
    vector<int> helper(TreeNode* node, int& distance) {
        vector<int> res(distance + 1, 0);
        if(!node) return res;
        if(!node->left and !node->right) {
            res[1] = 1;
            return res;
        }
        auto l = helper(node->left, distance);
        auto r = helper(node->right, distance);
        
        int psum = accumulate(begin(l), end(l), 0);
        for(int i = 0; i <= distance; i++) {
            sum += psum * r[i];
            psum -= l[distance - i];
        }
        
        
        for(int i = 0; i < distance; i++)
            res[i + 1] = l[i] + r[i];
        return res;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        helper(root, distance);
        
        return sum;
    }
};