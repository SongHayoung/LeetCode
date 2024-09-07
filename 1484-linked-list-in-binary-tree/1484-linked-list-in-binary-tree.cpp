/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> pi;
    vector<int> p;
    void buildPi() {
        pi = vector<int>(p.size());
        for(int i = 1, j = 0; i < p.size(); i++) {
            while(j > 0 and p[j] != p[i])
                j = pi[j-1];
            if(p[j] == p[i])
                pi[i] = ++j;
            
        }
    }
    bool kmp(vector<int>& s) {
        for(int i = 0, j = 0; i < s.size(); i++) {
            while(j > 0 and p[j] != s[i])
                j = pi[j-1];
            if(s[i] == p[j]) {
                if(++j == p.size())
                    return true;
            }
        }
        return false;
    }
    bool kmp(TreeNode* node, int i, int j) {
        if(!node) return false;
        
        while(j > 0 and p[j] != node->val)
            j = pi[j-1];
        if(node->val == p[j])
            if(++j == p.size())
                return true;
        
        if(kmp(node->left, i + 1, j))
            return true;
        if(kmp(node->right, i + 1, j))
            return true;
        
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        while(head) {
            p.push_back(head->val);
            head = head->next;
        }
        buildPi();
        
        return kmp(root, 0, 0);
    }
};