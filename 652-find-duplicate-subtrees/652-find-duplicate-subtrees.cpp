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
unordered_map<string, vector<TreeNode*>> m;
string search(TreeNode* node) {
	if(!node) return "";
	string key = '(' + search(node->left) + '#' + to_string(node->val) + '#' + search(node->right) + ')';
	m[key].push_back(node);
		return key;
}
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
	search(root);
	vector<TreeNode*> res;
	for(auto [key, values] : m) {
		if(values.size() > 1)
			res.push_back(values[0]);


	}


	return res;
    }
};
