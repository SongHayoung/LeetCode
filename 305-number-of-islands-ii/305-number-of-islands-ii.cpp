struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        
        return h1 ^ h2;  
    }
};
class Solution {
    unordered_map<pair<int,int>, pair<int,int>, pair_hash> g;
    pair<int,int> find(pair<int, int> p) {
        return g[p].first == -1 ? p : g[p] = find(g[p]);
    }
    // return number of merged islands
    int merge(pair<int, int> p, int island, int n, int m) {
        if(g.count(p)) return 1;
        g[p] = {-1, island};

        int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
        unordered_set<pair<int,int>, pair_hash> s;
        s.insert(p);
        int minIsland = island;
        pair<int, int> minPosition = p;
        for(int i = 0; i < 4; i++) {
            int ny = p.first + dy[i], nx = p.second + dx[i];
            if(g.count({ny,nx})) {
                auto position = find({ny,nx});
                s.insert(position);
                if(g[position].second < minIsland) {
                    minIsland = g[position].second;
                    minPosition = position;
                }
            }
        }
        
        int res = s.size() - 1;
        for(auto key : s) {
            if(key == minPosition) continue;
            g[key] = minPosition;
        }
        
        return res;
    }
public:
    vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
        int islandId = 1;
        int islands = 0;
        vector<int> res;
        for(auto position : positions) {
            int mergedIsland = merge({position[0], position[1]}, islandId++, n, m);
            islands = islands + 1 - mergedIsland;
            res.push_back(islands);
        }
        return res;
    }
};