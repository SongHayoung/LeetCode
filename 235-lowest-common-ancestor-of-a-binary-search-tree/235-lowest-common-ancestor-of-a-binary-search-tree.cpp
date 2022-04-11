/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ptree{root}, qtree{root};
        while(ptree.back()->val != p->val) {
            if(ptree.back()->val > p->val)
                ptree.push_back(ptree.back()->left);
            else
                ptree.push_back(ptree.back()->right);
        }
        while(qtree.back()->val != q->val) {
            if(qtree.back()->val > q->val)
                qtree.push_back(qtree.back()->left);
            else
                qtree.push_back(qtree.back()->right);
        }
        while(ptree.back()->val != qtree.back()->val) {
            if(qtree.size() == ptree.size()) {
                qtree.pop_back();
                ptree.pop_back();
            } else if(qtree.size() > ptree.size()) {
                qtree.pop_back();
            } else {
                ptree.pop_back();
            }
        }
        return qtree.back();
    }
};