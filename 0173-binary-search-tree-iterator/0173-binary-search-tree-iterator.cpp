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
    vector<TreeNode*> st;
public:
    void push(TreeNode* n) {
        if(!n) return;
        TreeNode* runner = n;
        while(runner) {
            st.push_back(runner);
            runner = runner->left;
        }
    }
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        int res = st.back()->val;
        TreeNode* x = st.back()->right; st.pop_back();
        push(x);
        return res;
    }
    
    bool hasNext() {
        return st.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */