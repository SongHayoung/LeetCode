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
    int res = 0;
    //lower conseq, upper conseq
    pair<int,int> getLength(TreeNode* node) {
        if(!node) return {0, 0};
        auto [ll, lu] = getLength(node->left);
        auto [rl, ru] = getLength(node->right);
        int lower = 1, upper = 1;
        if(node->left and node->left->val == node->val - 1) {
            lower = max(lower, ll + 1);
        }
        if(node->left and node->left->val == node->val + 1) {
            upper = max(upper, lu + 1);
        }


        if(node->right and node->right->val == node->val - 1) {
            lower = max(lower, rl + 1);
        }
        if(node->right and node->right->val == node->val + 1) {
            upper = max(upper, ru + 1);
        }
        
        res = max({res, lower, upper});
        
        if(node->left and node->right) {
            if(node->left->val == node->val - 1 and node->right->val == node->val + 1) {
                res = max(res, 1 + ll + ru);
            }
            if(node->right->val == node->val - 1 and node->left->val == node->val + 1) {
                res = max(res, 1 + rl + lu);
            }
        }
        
        return {lower, upper};
    }
public:
    int longestConsecutive(TreeNode* root) {
        getLength(root);
        return res;
    }
};