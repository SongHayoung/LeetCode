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
    void travel(TreeNode* node, deque<int>& nums) {
        if(!node) return;
        travel(node->left, nums);
        nums.push_back(node->val);
        travel(node->right, nums);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> nums;
        travel(root, nums);
        while(nums.size() > k) {
            if(abs(target - nums.front()) > abs(target - nums.back()))
                nums.pop_front();
            else
                nums.pop_back();
        }
        return vector<int>(nums.begin(),nums.end());
    }
};