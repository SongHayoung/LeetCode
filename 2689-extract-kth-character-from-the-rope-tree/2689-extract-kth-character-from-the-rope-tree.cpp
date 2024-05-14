/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
    char dfs(RopeTreeNode* n, int k) {
        if(n->len == 0) return n->val[k-1];
        if(!n->left) return dfs(n->right,k);
        if(!n->right) return dfs(n->left,k);
        if(n->left->len >= k) return dfs(n->left,k);
        if(n->left->len == 0 and n->left->val.length() >= k) return dfs(n->left,k);
        return dfs(n->right, k - max(n->left->len, (int)n->left->val.length()));
    }
public:
    char getKthCharacter(RopeTreeNode* root, int k) {
        return dfs(root,k);
    }
};