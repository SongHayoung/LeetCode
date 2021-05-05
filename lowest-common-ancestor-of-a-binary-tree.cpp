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
    set<TreeNode*> s;
    bool findNode(TreeNode* node, TreeNode* target, set<TreeNode*>& s) {
        if(node == target) {s.insert(node); return true;}
        if(node->left != NULL && findNode(node->left, target, s)) {
            s.insert(node);
            return true;
        }
        if(node->right != NULL && findNode(node->right, target, s)) {
            s.insert(node);
            return true;
        }
        return false;
    }

    pair<TreeNode*,bool> findNode(TreeNode* node, TreeNode* target) {
        if(node == target) return {NULL, true};
        if(node->left != NULL) {
            auto p = findNode(node->left, target);
            if(p.second) {
                if(p.first != NULL || !s.count(node)) return p;
                return {node, true};
            }
        }
        if(node->right != NULL) {
            auto p = findNode(node->right, target);
            if(p.second) {
                if(p.first != NULL || !s.count(node)) return p;
                return {node, true};
            }
        }
        return {NULL, false};
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        findNode(root, p, s);
        if(s.count(q)) return q;
        return findNode(root, q).first;
    }
};

