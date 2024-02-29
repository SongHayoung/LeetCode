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
    vector<int> order;
    bool helper(TreeNode* node, int level) {
        if(!node) return true;
        if((level & 1) and (node->val & 1)) return false;
        if(!(level & 1) and (!(node->val & 1))) return false;
        if(order.size() == level) order.push_back(node->val + (level & 1 ? 1 : -1));
        if(level & 1) {
            if(order[level] <= node->val) return false;
        } else {
            if(order[level] >= node->val) return false;
        }
        order[level] = node->val;
        return helper(node->left, level + 1) and helper(node->right, level + 1);
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        return helper(root, 0);
    }
};