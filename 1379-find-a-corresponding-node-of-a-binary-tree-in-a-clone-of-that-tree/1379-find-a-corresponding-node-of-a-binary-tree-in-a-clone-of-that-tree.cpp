/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* helper(TreeNode* o, TreeNode* t, TreeNode* c) {
        if(!o) return NULL;
        if(o == t) return c;
        auto l = helper(o->left, t, c->left);
        if(l != NULL) return l;
        return helper(o->right, t, c->right);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!target) return NULL;
        return helper(original, target, cloned);
    }
};