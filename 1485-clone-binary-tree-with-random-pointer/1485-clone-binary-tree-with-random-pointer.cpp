/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
    unordered_map<Node*, NodeCopy*> mp;
    void dfs(Node* node) {
        if(!node) return;
        mp[node] = new NodeCopy(node->val);
        dfs(node->left);
        dfs(node->right);
    }
    NodeCopy* dfs2(Node* node) {
        if(!node) return nullptr;
        auto res = mp[node];
        res->left = dfs2(node->left);
        res->right = dfs2(node->right);
        if(node->random)
            res->random = mp[node->random];
        return res;
    }
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        dfs(root);
        return dfs2(root);
    }
};