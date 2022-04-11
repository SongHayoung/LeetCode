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
    Node* findRightChild(Node* node, int val) {
        while(node->left and node->left->val > val)
            node = node->left;
        return node;
    }
    Node* findParentRightChild(Node* node, int val) {
        while(node) {
            if(node->val > val) return node;
            if(node->right and node->right->val > val)
                return findRightChild(node->right, val);
            node = node->parent;
        }
        return node;
    }
public:
    Node* inorderSuccessor(Node* node) {
        if(node->right != NULL) return findRightChild(node->right, node->val);
        if(node->parent != NULL) return findParentRightChild(node->parent, node->val);
    
        return NULL;
    }
};