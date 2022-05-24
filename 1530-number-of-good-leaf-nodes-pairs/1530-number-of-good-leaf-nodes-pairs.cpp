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
class Solution {
    vector<string> code;
    void helper(TreeNode* node, string c) {
        if(!node) return;
        if(!node->left and !node->right) {
            code.push_back(c);
        } else {
            helper(node->left, c + '0');
            helper(node->right, c + '1');
        }
    }
    int distance(string& c1, string& c2) {
        int n = c1.length(), m = c2.length();
        if(n < m) return distance(c2, c1);
        
        int diff = n - m;
        int i = 0;
        while(i < m and c1[i] == c2[i]) i++;
        return (n - i) * 2 - diff;
    }
public:
    int countPairs(TreeNode* root, int dis) {
        helper(root, "");
        int res = 0, n = code.size();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++) {
                if(distance(code[i], code[j]) <= dis){
                  res++;  
                } 
            }
        
        return res;
    }
};