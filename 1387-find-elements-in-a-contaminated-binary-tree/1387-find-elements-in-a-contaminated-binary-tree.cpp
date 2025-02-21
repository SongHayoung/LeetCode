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
class FindElements {
    TreeNode* root;
public:
    FindElements(TreeNode* root): root(root) {}
    vector<int> getBit(int n) {
        vector<int> res;
        while(n) {
            res.push_back(n & 1);
            n>>=1;
        }
        reverse(begin(res), end(res));
        return res;
    }
    bool find(int target) {
        if(target == 0) return root;
        TreeNode* node = root;
        vector<int> bit = getBit(target + 1);
        for(int i = 1; i < bit.size(); i++) {
            if(bit[i]) {
                if(!node->right) return false;
                node = node->right;
            } else {
                if(!node->left) return false;
                node = node->left;
            }
        }

        return node;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
