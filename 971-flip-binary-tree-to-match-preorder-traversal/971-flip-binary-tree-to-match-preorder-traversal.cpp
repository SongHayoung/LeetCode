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
    bool flag = true;

    void isFilp(int& idx, set<int> &res, TreeNode *node, vector<int> &voyage) {
        if(voyage[idx] != node->val) {
            flag = false;
            return;
        }
        bool left = node->left != nullptr, right = node->right != nullptr;
        idx++;
        if (left) {
            if (voyage[idx] != node->left->val) {
                if(right && voyage[idx] == node->right->val) {
                    res.insert(node->val);
                    isFilp(idx, res, node->right, voyage);
                } else {
                    flag = false;
                }
            } else {
                isFilp(idx, res, node->left, voyage);
            }
        }

        if (right) {
            if (voyage[idx] != node->right->val) {
                if(left && voyage[idx] == node->left->val) {
                    res.insert(node->val);
                    isFilp(idx,res, node->left, voyage);
                } else {
                    flag = false;
                }
            } else {
                isFilp(idx, res, node->right, voyage);
            }
        }
    }

public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
        if (root->val != voyage[0])
            return vector<int>{-1};

        set<int> res;
        int idx = 0;
        isFilp(idx, res, root, voyage);

        return flag ? vector<int>(res.begin(), res.end()) : vector<int>{-1};
    }
};