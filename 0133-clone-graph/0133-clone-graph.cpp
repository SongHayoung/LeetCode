/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<int, Node*> m;
        unordered_map<int, set<int>> graph;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            auto n = q.front(); q.pop();
            m[n->val] = new Node(n->val);
            for(auto nxt : n->neighbors) {
                graph[n->val].insert(nxt->val);
                if(m.count(nxt->val)) continue;
                q.push(nxt);
            }
        }
        
        for(auto& [val, n]: m) {
            for(auto near : graph[val]) {
                n->neighbors.push_back(m[near]);
            }
        }
        
        return m[node->val];
    }
};