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
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T,U>& l, const std::pair<T,U>& r) {
    return {l.first + r.first, l.second + r.second};
}
class Solution {
private:
    map<int, pair<long, int>> levelSum;

    void recursiveSumTree(int level, TreeNode* node) {
        if(!levelSum.count(level)) {
            levelSum[level] = {0, 0};
        }
        pair<long, int> cur = {node->val, 1};
        levelSum[level] = cur + levelSum[level];

        if(node->left != nullptr) {
            recursiveSumTree(level + 1, node->left);
        }

        if(node->right != nullptr) {
            recursiveSumTree(level + 1, node->right);
        }

        return;
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        recursiveSumTree(0, root);

        vector<double> res;
        for(auto entity : levelSum) {
            res.push_back(1.0 * entity.second.first / entity.second.second);
        }

        return res;
    }
};