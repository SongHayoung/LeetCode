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
class BSTIterator {
    vector<int> A;
    int p = 0;
    void init(TreeNode* node) {
        if(!node) return;
        init(node->left);
        A.push_back(node->val);
        init(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        A.push_back(INT_MIN);
        init(root);
    }
    
    bool hasNext() {
        return p + 1 < A.size();
    }
    
    int next() {
        return A[++p];
    }
    
    bool hasPrev() {
        return p > 1;
    }
    
    int prev() {
        return A[--p];
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */