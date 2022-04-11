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
    bool res = true;
    int travel(TreeNode* node, int lvl) {
        if(!node) return lvl-1;
        auto llvl = travel(node->left, lvl + 1);
        auto rlvl = travel(node->right, lvl + 1);
        int milvl = min(llvl, rlvl), malvl = max(llvl, rlvl);
        if(malvl - milvl > 1) res = false;
        return malvl;
    }
public:
    bool isBalanced(TreeNode* root) {
        travel(root, 0);
        return res;
    }
};