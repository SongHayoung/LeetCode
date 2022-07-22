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
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return root;
        TreeNode *res = root, *r = nullptr;
        vector<TreeNode*> st;
        while(res->left) {
            auto nl = res->left;
            res->left = r;
            st.push_back(res);
            r = res->right;
            res = nl;
        }
        st.push_back(res);
        res->left = r;
        TreeNode *l = nullptr;
        for(int i = 0; i < st.size(); i++) {
            st[i]->right = l;
            l = st[i];
        }
        return res;
    }
};