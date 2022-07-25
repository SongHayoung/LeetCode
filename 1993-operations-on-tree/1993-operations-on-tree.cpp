class LockingTree {
    vector<vector<int>> adj, radj;
    unordered_map<int, int> l;
    bool updfs(int u) {
        while(!radj[u].empty()) {
            if(l.count(u)) return false;
            u = radj[u][0];
        }
        return !l.count(u);
    }
    bool downdfs(int u) {
        bool res = l.count(u);
        if(l.count(u)) l.erase(u);
        for(auto v : adj[u]) {
            res |= downdfs(v);
        }
        return res;
    }
public:
    LockingTree(vector<int>& A) {
        adj = radj = vector<vector<int>>(A.size());
        for(int i = 0; i < A.size(); i++) {
            if(A[i] == -1) continue;
            adj[A[i]].push_back(i);
            radj[i].push_back(A[i]);
        }
    }
    
    bool lock(int num, int user) {
        if(l.count(num)) return false;
        l[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(!l.count(num) or l[num] != user) return false;
        l.erase(num);
        return true;
    }
    
    bool upgrade(int num, int user) {
        if(l.count(num)) return false;
        if(!updfs(num)) return false;
        if(!downdfs(num)) return false;
        return lock(num, user);
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */