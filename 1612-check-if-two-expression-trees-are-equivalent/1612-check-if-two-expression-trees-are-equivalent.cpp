/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<char, int> freq;
    void dfs(Node* node, int v) {
        if(!node) return;
        if(isalpha(node->val)) {
            freq[node->val] += v;
        } else {
            dfs(node->left, v);
            dfs(node->right, v);
        }
    }
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        dfs(root1, 1);
        dfs(root2, -1);
        for(auto [k, v] : freq) if(v) return false;
        return true;
    }
};