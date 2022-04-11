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
vector<vector<int>> res;
bool isLeafNode(TreeNode* node) {
	if(!node->left and !node->right){
res.back().push_back(node->val);
 return true;
}

if(node->left and isLeafNode(node->left)) {
node->left = NULL;
}
if(node->right and isLeafNode(node->right)) {
	node->right = NULL;
}
return false;
}
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
	res.push_back(vector<int>());
	while(!isLeafNode(root)) {
		res.push_back(vector<int>());
}
return res;
    }
};
