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
    vector<int> toRight(list<TreeNode*>& l) {
        vector<int> res;
        list<TreeNode*> next;
        for(auto& node : l) {
            res.push_back(node->val);
            if(node->left != nullptr) next.push_back(node->left);
            if(node->right != nullptr) next.push_back(node->right);
        }
        l = next;
        return res;
    }
    vector<int> toLeft(list<TreeNode*>& l) {
        vector<int> res = toRight(l);
        reverse(res.begin(), res.end());
        return res;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        list<TreeNode*> nodes{root};
        while(nodes.size()) {
            if(!nodes.empty()) res.push_back(toRight(nodes));
            if(!nodes.empty()) res.push_back(toLeft(nodes));
        }
        return res;
    }
};
