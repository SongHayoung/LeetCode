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
    string start = "", dest = "";
    string path = "";
    void helper(TreeNode* node, int& s, int& e) {
        if(!node or (start.length() != 0 and dest.length() != 0)) return;
        if(node->val == s) {
            start = path;
        } else if(node->val == e) {
            dest = path;
        }
        path.push_back('L');
        helper(node->left, s, e);
        path.back() = 'R';
        helper(node->right, s, e);
        path.pop_back();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        helper(root, startValue, destValue);
        string res = "";
        int common = 0;
        for(int i = 0; i < min(start.length(), dest.length()); i++) {
            if(start[i] == dest[i])
                common = i + 1;
            else break;
        }
        start = start.substr(common);
        dest = dest.substr(common);
        for(auto& ch : start)
            ch = 'U';
        return start + dest;
    }
};