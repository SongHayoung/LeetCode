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
 bool isValidSequence(TreeNode* r, vector<int>& a, int p = 0) {
    if (p >= a.size() || r == nullptr || r->val != a[p])
        return false;
    return (r->left == r->right && p == a.size() - 1) ||
        isValidSequence(r->left, a, p + 1) || isValidSequence(r->right, a, p + 1);
}
};