class ThroneInheritance {
    unordered_set<string> dead;
    unordered_map<string, vector<string>> adj;
    string root;
    void helper(vector<string>& res, string& u) {
        if(!dead.count(u)) res.push_back(u);
        for(auto& v : adj[u])
            helper(res, v);
    }
public:
    ThroneInheritance(string kingName) : root(kingName) {}
    
    void birth(string parentName, string childName) {
        adj[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        helper(res, root);
        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */