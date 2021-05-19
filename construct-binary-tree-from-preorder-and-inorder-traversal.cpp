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
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        if(p.empty()) return nullptr;
        int rootPos = distance(i.begin(), find(i.begin(), i.end(), p[0]));
        vector<int> pl(p.begin() + 1, p.begin() + 1 + rootPos), pr(p.begin() + 1 + rootPos, p.end()), il(i.begin(), i.begin() + rootPos), ir(i.begin() + rootPos + 1, i.end());
        return new TreeNode(p[0], buildTree(pl, il), buildTree(pr, ir));
    }
};
