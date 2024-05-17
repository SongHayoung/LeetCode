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
    pair<int, int> helper(TreeNode* n) {
        if(!n) return {INT_MAX, INT_MAX};
        if(n->val == 0) return {0,1};
        if(n->val == 1) return {1,0};
        auto [n1,y1] = helper(n->left);
        auto [n2,y2] = helper(n->right);
        if(n->val == 2) {
            return {n1 + n2, min({y1 + n2, y2 + n1, y1 + y2})};
        }
        if(n->val == 3) {
            return {min({n1 + n2, y1 + n2, y2 + n1}), y1 + y2};
        }
        if(n->val == 4) {
            return {min(n1 + n2, y1 + y2), min(n1 + y2, n2 + y1)};
        }
        return {min(y1,y2), min(n1,n2)};
    }
public:
    int minimumFlips(TreeNode* root, bool result) {
        auto [n,y] = helper(root);
        return result ? y : n;
    }
};