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
    void buildNode(string &s, int &pos, TreeNode* cur) {
        if(pos >= s.length() || s[pos] == ')'){
            pos++;
            return;   
        }
        
        int flag = s[pos] == '-' ? -1 : 1, val = 0;
        if(flag == -1)
            pos++;
        for(; pos < s.length(); pos++) {
            if('0' <= s[pos] && s[pos] <= '9')
                val = (val<<3) + (val<<1) + (s[pos] & 0b1111);
            else
                break;
        }
        cur->val = flag * val;
        if(s[pos] == ')') {
            pos++;
            return;
        } else if(s[pos] == '(') {
            pos++;
            cur->left = new TreeNode();
            buildNode(s, pos, cur->left);
        }

        if(s[pos] == ')') {
            pos++;
            return;
        } else if(s[pos] == '(') {
            pos++;
            cur->right = new TreeNode();
            buildNode(s, pos, cur->right);
        }
        
        pos++;
        return;
    }
public:
    TreeNode* str2tree(string s) {
        if(s.length() == 0)
            return nullptr;
        TreeNode* root = new TreeNode();
        int pos = 0;
        buildNode(s,pos,root);
        return root;
    }
};
