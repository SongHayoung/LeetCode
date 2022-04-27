class MovieRentingSystem {
    unordered_map<int,set<pair<int,int>>> mov;
    vector<unordered_map<int,pair<int,int>>> shp;
    
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
    
    bool duplicated(array<int,3>& a, array<int,3> b) {
        return a == b;
    }
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        shp = vector<unordered_map<int,pair<int,int>>>(n);
        for(auto& e : entries) {
            auto s = e[0], m = e[1], p = e[2];
            mov[m].insert({p,s});
            shp[s][m] = {p,1};
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        for(auto& [price, shop] : mov[movie]) {
            if(res.size() == 5) break;
            res.push_back(shop);
        }
        return res;
    }
    
    
    
    void rent(int shop, int movie) {
        if(shp[shop].count(movie)) {
            auto [p, h] = shp[shop][movie];
            if(!h) return;
            mov[movie].erase({p,shop});
            shp[shop][movie].second = 0;
            pq.push({p,shop,movie});
        }
    }
    
    void drop(int shop, int movie) {
        if(shp[shop].count(movie)) {
            auto [p, h] = shp[shop][movie];
            if(h) return;
            mov[movie].insert({p,shop});
            shp[shop][movie].second = 1;
        }
    }
    
    vector<vector<int>> report() {
        vector<array<int,3>> cheap;
        while(!pq.empty() and cheap.size() < 5) {
            auto [p, s, m] = pq.top(); pq.pop();
            if(shp[s][m].second) continue;
            if(!cheap.empty() and duplicated(cheap.back(), {p,s,m})) continue;
            cheap.push_back({p,s,m});
        }
        vector<vector<int>> res;
        for(auto& [p, s, m] : cheap) {
            pq.push({p,s,m});
            res.push_back({s,m});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */