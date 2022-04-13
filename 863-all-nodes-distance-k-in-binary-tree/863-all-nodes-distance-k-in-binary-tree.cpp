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
    vector<int> res;
    int getDistance(TreeNode* node, TreeNode* target, int k, int dis) {
        if(!node) return INT_MIN;
        if(node->val == target->val) {
            getDistance(node->left, target, k, 1);
            getDistance(node->right, target, k, 1);
            return 1;
        } else if(dis == k) {
            res.push_back(node->val);
            return INT_MIN;
        } else if(dis != -1 and dis < k) {
            getDistance(node->left, target, k, dis + 1);
            getDistance(node->right, target, k, dis + 1);
            return INT_MIN;
        } else {
            int lDis = getDistance(node->left, target, k, dis);
            if(lDis == k) {
                res.push_back(node->val);
                return lDis + 1;
            } else if(lDis < k and lDis > 0) {
                getDistance(node->right,target,k,lDis + 1);
                return lDis + 1;
            }
            int rDis = getDistance(node->right, target, k, dis);
            if(rDis == k) {
                res.push_back(node->val);
            } else if(rDis < k and rDis > 0) {
                getDistance(node->left,target,k,rDis + 1);
                return rDis + 1;
            }
            return INT_MIN;
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k != 0)
            getDistance(root,target,k,-1);
        else if(k == 0)
                res.push_back(target->val);
        return res;
    }
};