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
    int parseValue(string& t, int& pos) {
        int res = 0;
        for(; pos < t.length() && '0' <= t[pos] && t[pos] <= '9'; pos++) {
            res = (res<<3) + (res<<1) + (t[pos] & 0b1111);
        }
        return res;
    }
    bool hasChild(string& t, int pos, int target) {
        if(pos + target >= t.length()) return false;
        for(int i = pos; i < pos + target ; i++) {
            if(t[i] != '-') return false;
        }
        return true;
    }
    TreeNode* parseTree(string& t, int& pos, int depth) {
        if(t.length() <= pos)
            return nullptr;
        TreeNode* node = new TreeNode(parseValue(t, pos));
        if(hasChild(t, pos, depth)) {
            pos += depth;
            node->left = parseTree(t, pos, depth + 1);

            if(hasChild(t, pos, depth)) {
                pos += depth;
                node->right = parseTree(t, pos, depth + 1);
            }
        }
        return node;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int pos = 0;
        return parseTree(traversal, pos, 1);
    }
};