/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    struct Node {
        int val;
        list<Node*> near;
        Node(int x) : val(x) {}
        Node(int x, Node* n) : val(x), near{n} {}
    };
    Node* buildGraph(TreeNode* root, TreeNode* target) {
        Node* t;
        queue<pair<TreeNode*,Node*>> q;
        q.push({root, new Node(root->val)});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if(p.first == target) t = p.second;
            if(p.first->left != NULL) {
                Node* left = new Node(p.first->left->val, p.second);
                p.second->near.push_back(left);
                q.push({p.first->left, left});
            }
            if(p.first->right != NULL) {
                Node* right = new Node(p.first->right->val, p.second);
                p.second->near.push_back(right);
                q.push({p.first->right, right});
            }
        }
        return t;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!k) return {target->val};
        Node* t = buildGraph(root, target);
        vector<int> res;
        queue<Node*> q;
        set<Node*> v;
        q.push(t), v.insert(t);
        while(k--) {
            int sz = q.size();
            while(sz--) {
                auto n = q.front();
                q.pop();
                for(auto near : n->near) {
                    if(v.count(near)) continue;
                    v.insert(near);
                    q.push(near);
                }
            }
        }
        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};
