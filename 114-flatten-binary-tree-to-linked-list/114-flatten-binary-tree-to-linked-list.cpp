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
    pair<TreeNode*, TreeNode*> flat(TreeNode* node) {
        TreeNode *tail = NULL, *l = node->left, *r = node->right;
        node->right = node->left = NULL;
        if(l) {
            auto [lhead, ltail] = flat(l);
            node->right = lhead; tail = ltail;
        }
        if(r) {
            auto [rhead, rtail] = flat(r);
            if(!node->right) node->right = rhead;
            else tail->right = rhead;
            tail = rtail;
        }
        return {node, tail ? tail : node};
    }
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flat(root);
    }
};