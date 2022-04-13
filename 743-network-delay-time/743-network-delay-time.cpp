class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> visit(n + 1,-1);
        vector<vector<pair<int,int>>> t(n + 1);
        for(auto time : times) {
            t[time[0]].push_back({time[1],time[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        visit[k] = 0;
        pq.push({0,k});
        while(!pq.empty()) {
            auto [takes, node] = pq.top(); pq.pop();
            for(auto [nxt, req] : t[node]) {
                if(visit[nxt] == -1 or visit[nxt] > req + takes) {
                    visit[nxt] = req + takes;
                    pq.push({req+takes, nxt});
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++) {
            res = max(res, visit[i]);
            if(visit[i] == -1) return -1;
        }
        return res;
    }
};