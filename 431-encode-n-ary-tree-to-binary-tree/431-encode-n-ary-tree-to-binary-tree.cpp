/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(!root) return NULL;
        TreeNode* ret = new TreeNode(root->val);
        if(root->children.size()) {
            TreeNode* sameLevel = ret->left = encode(root->children[0]);
            for(int i = 1; i < root->children.size(); i++) {
                sameLevel->right = encode(root->children[i]);
                sameLevel = sameLevel->right;
            }
        }
        return ret;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(!root) return NULL;
        Node* ret = new Node(root->val);
        TreeNode* children = root->left;
        while(children) {
            ret->children.push_back(decode(children));
            children = children->right;
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));