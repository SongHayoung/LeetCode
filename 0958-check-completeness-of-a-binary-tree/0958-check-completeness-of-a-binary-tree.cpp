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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            bool eof = false;
            while(sz--) {
                auto n = q.front(); q.pop();
                if(eof) {
                    if(n->left or n->right) return false;
                } else {
                    if(n->left and n->right) {
                        q.push(n->left);
                        q.push(n->right);
                    } else if(n->left and !n->right) {
                        q.push(n->left);
                        eof = true;
                    } else if(!n->left and n->right) return false;
                    else eof = true;
                }
            }
            
            if(eof) {
                while(!q.empty()) {
                    auto n = q.front(); q.pop();
                    if(n->left or n->right) return false;
                }
            }
        }
        return true;
    }
};
