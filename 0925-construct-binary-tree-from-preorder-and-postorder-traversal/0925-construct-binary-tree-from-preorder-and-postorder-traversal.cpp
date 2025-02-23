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
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int& pre, int& post, unordered_set<int>& build) {
        if(pre == preorder.size() or post == postorder.size()) return NULL;
        if(preorder[pre] == postorder[post]) {
            build.insert(preorder[pre]);
            post++;
            return new TreeNode(preorder[pre++]);
        }
        TreeNode* node = new TreeNode(preorder[pre]);
        build.insert(preorder[pre++]);
        
        node->left = helper(preorder,postorder,pre,post,build);
        if(pre == preorder.size() or post == postorder.size()) return node;
        if(build.count(postorder[post])) {
            post++;
            return node;
        }
        
        node->right = helper(preorder,postorder,pre,post,build);
        
        post++;
        return node;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int pre = 0, post = 0;
        unordered_set<int> build;
        return helper(preorder,postorder,pre,post,build);
    }
};