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

class Solution {
    unordered_map<Node*, Node*> par;
    unordered_map<Node*, int> level;
    void dfs(Node* u, Node* p, int lv) {
        level[u] = lv;
        par[u] = p;
        for(auto& v : u->children)
            dfs(v,u,lv+1);
    }
    bool subOf(Node* u, Node* v) {
        if(level[u] >= level[v]) return false;
        Node* runner = v;
        while(level[runner] > level[u]) runner = par[runner];
        return runner == u;
    }
    void cut(Node* u, Node* v) {
        vector<Node*> newChild;
        for(auto& child : u->children)
            if(child != v)
                newChild.push_back(child);
        u->children = newChild;
    }
public:
    Node* moveSubTree(Node* root, Node* p, Node* q) {
        Node* dummy = new Node(-1, {root});
        dfs(root,dummy,0);
        if(par[p] == q) return root;
        if(subOf(q,p)) {
            cut(par[p],p);
            q->children.push_back(p);
        } else if(subOf(p,q)) {
            cut(par[q],q);
            q->children.push_back(p);
            for(auto& child : par[p]->children)
                if(child == p)
                    child = q;
        } else {
            cut(par[p],p);
            q->children.push_back(p);
        }
        return dummy->children[0]; 
    }
};