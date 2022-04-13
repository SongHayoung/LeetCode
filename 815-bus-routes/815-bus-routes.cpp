class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int, vector<int>> g;
        for(int i = 0; i < routes.size(); i++) {
            for(auto stop : routes[i]) {
                g[stop].push_back(i);
            }
        }
        unordered_set<int> v{source};
        int time = 1;
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto stop = q.front(); q.pop();
                for(auto r : g[stop]) {
                    for(auto next : routes[r]) {
                        if(!v.count(next)) {
                            q.push(next);
                            v.insert(next);
                            if(next == target)
                                return time;
                        }
                    }
                    routes[r].clear();
                }
            }
            ++time;
        }
        
        return -1;
    }
};