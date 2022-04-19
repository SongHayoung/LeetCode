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
    vector<TreeNode*> WA;
    TreeNode* prv = nullptr;
    void helper(TreeNode* node) {
        if(!node) return;
        helper(node->left);
        if(prv and prv->val > node->val) {
            WA.push_back(prv);
            if(WA.size() >= 2) WA.pop_back();
            WA.push_back(node);
        }
        prv = node;
        helper(node->right);
        
    }
public:
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(WA[0]->val, WA.back()->val);
    }
};