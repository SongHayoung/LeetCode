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
class CBTInserter { 
    TreeNode* dummy;
    int mask = 1;
    int getFrontMask() {
        int fMask = 1;
        
        while(fMask <= mask) fMask<<=1;
        
        return fMask>>1;
    }
    int traverse(int fMask, TreeNode* node, int& val) {
        if(fMask == 1) {
            if(mask & fMask) node->right = new TreeNode(val);
            else node->left = new TreeNode(val);
            return node->val;
        }
        
        if(mask & fMask) return traverse(fMask>>1, node->right, val);
        else return traverse(fMask>>1, node->left, val);
    }
public:
    CBTInserter(TreeNode* root) {
        dummy = new TreeNode(-1, nullptr, root);
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()) {
            mask++;
            auto node = q.front(); q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    
    int insert(int val) {
        int fMask = getFrontMask();
        int res = traverse(fMask, dummy, val);
        mask++;
        return res;
    }
    
    TreeNode* get_root() {
        return dummy->right;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */