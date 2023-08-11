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
    priority_queue<int> dfs(TreeNode* node, int k, int& res) {
        priority_queue<int> self;
        if(node->left) {
            auto le = dfs(node->left,k,res);
            while(le.size()) {
                self.push(le.top());
                le.pop();
            }
        }
        if(node->right) {
            auto ri = dfs(node->right,k,res);
            while(ri.size()) {
                self.push(ri.top());
                ri.pop();
            }
        }
        while(self.size() > k) self.pop();
        if(self.size() == k and self.top() < node->val) res += 1;
        self.push(node->val);
        return self;
    }
public:
    int countGreatEnoughNodes(TreeNode* root, int k) {
        int res = 0;
        dfs(root,k,res);
        return res;
    }
};