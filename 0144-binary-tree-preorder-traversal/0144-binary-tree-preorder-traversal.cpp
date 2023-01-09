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
    void preorder(TreeNode* node, vector<int>& res) {
        if(!node) return;
        res.push_back(node->val);
        preorder(node->left, res);
        preorder(node->right, res);
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> st{root};
        while(!st.empty()) {
            auto node = st.back(); st.pop_back();
            if(!node) continue;
            res.push_back(node->val);
            st.push_back(node->right);
            st.push_back(node->left);
        }
        //preorder(root, res);
        return res;
    }
};