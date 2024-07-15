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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> node;
        unordered_set<int> child;
        for(auto desc : descriptions) {
            int p = desc[0];
            int me = desc[1];
            bool left = desc[2];
            child.insert(me);
            if(!node.count(p)) {
                node[p] = new TreeNode(p);
            }
            if(!node.count(me)) {
                node[me] = new TreeNode(me);
            }
            if(left) {
                node[p]->left = node[me];
            } else {
                node[p]->right = node[me];
            }
        }
        
        for(auto [val, n]: node) {
            if(child.count(val)) continue;
            return n;
        }
        return nullptr;
    }
};