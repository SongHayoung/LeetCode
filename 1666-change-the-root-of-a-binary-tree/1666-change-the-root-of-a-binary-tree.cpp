/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    void unlink(Node* child, Node* par) {
        if(child->left == par) child->left = nullptr;
        if(child->right == par) child->right = nullptr;
    }
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        Node* res = leaf;
        Node* child = leaf->parent, *par = leaf;
        while(par != root) {
            if(par->left) swap(par->left, par->right);
            Node* nchild = child->parent;
            unlink(child, par);
            par->left = child;
            child->parent = par;
            par = child;
            child = nchild;
        }
        res->parent = nullptr;
        return res;
    }
};