class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int n = coins.size();
        vector<vector<int>> path(n);
        vector<bool> inc(n);
        vector<int> cost(n, INT_MAX);
        cost[0] = 0;
        path[0] = {0};
        inc[0] = true;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [c, p] = pq.top(); pq.pop();
            if(cost[p] != c) continue;
            inc[p] = false;
            for(int i = p + 1; i < min(n, p + maxJump + 1); i++) {
                if(coins[i] == -1) continue;
                if(cost[i] < cost[p] + coins[i]) continue;
                if(cost[i] > cost[p] + coins[i]) {
                    cost[i] = cost[p] + coins[i];
                    path[i] = path[p];
                    path[i].push_back(i);
                    pq.push({cost[i], i});
                } else if(cost[i] == cost[p] + coins[i]) {
                    vector<int> tmp = path[p];
                    tmp.push_back(i);
                    path[i] = min(path[i], tmp);
                    if(!inc[i]) {
                        inc[i] = true;
                        pq.push({cost[i], i});
                    }
                }
            }
        }
        
        auto& res = path[n - 1];
        for(auto& p : res) p += 1;
        return res;
    }
};