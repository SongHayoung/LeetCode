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
    queue<int> q;
    void inOrder(TreeNode* node) {
        if(node->left != nullptr) inOrder(node->left);
        q.push(node->val);
        if(node->right != nullptr) inOrder(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        if(root != nullptr)
            inOrder(root);
    }

    int next() {
        int res = q.front();
        q.pop();
        return res;
    }

    bool hasNext() {
        return q.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */