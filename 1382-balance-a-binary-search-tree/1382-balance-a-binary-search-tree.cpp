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
    vector<TreeNode*> orderedNode;
    void pushRecursive(TreeNode* node) {
        if(!node) return;
        pushRecursive(node->left);
        orderedNode.push_back(node);
        pushRecursive(node->right);
    }
    
    TreeNode* reorder(int s, int e) {
        if(s > e) return NULL;
        int m = (s + e) >> 1;
        TreeNode* head = orderedNode[m];
        head->left = reorder(s, m - 1);
        head->right = reorder(m + 1, e);
        return head;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        pushRecursive(root);
        return reorder(0, orderedNode.size() - 1);
    }
};
