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
    bool eq(TreeNode* o, TreeNode* t) {
        if(!o)
            return !t;
        if(!t)
            return !o;
        if(o->val != t->val)
            return false;
        if(!eq(o->left, t->left))
            return false;
        return eq(o->right, t->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> cand;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            if(node->val == subRoot->val)
                cand.push_back(node);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        for(auto c : cand)
            if(eq(c,subRoot))
                return true;
        return false;
    }
};