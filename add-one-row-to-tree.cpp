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
private:
    void rebalance(TreeNode* node, int level, const int& d, const int &v) {
        if(level + 1 == d) {
            node->left = new TreeNode(v, node->left, nullptr);
            node->right = new TreeNode(v, nullptr, node->right);
            return;
        }

        if(node->left != nullptr) {
            rebalance(node->left, level + 1, d, v);
        }

        if(node->right != nullptr) {
            rebalance(node->right, level + 1, d, v);
        }

        return;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            root = new TreeNode(v, root, nullptr);
        } else {
            rebalance(root, 1, d, v);   
        }
        return root;
    }
};
