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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        long res = LONG_MIN;
        int lvl = 1, curLvl = 1;
        while(!q.empty()) {
            long sum = 0;
            int count = q.size();
            while(count--) {
                auto node = q.front(); q.pop();
                
                sum += node->val;
                
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
                
            }
            if(res < sum) {
                res = sum;
                lvl = curLvl;
            }
            curLvl++;
        }
        return lvl;
    }
};