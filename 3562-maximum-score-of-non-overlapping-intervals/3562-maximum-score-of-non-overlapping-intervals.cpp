class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        vector<array<long long,4>> S;
        for(int i = 0; i < intervals.size(); i++) {
            S.push_back({1ll * intervals[i][0],1ll * intervals[i][1],1ll * intervals[i][2],1ll * i});
        }
        sort(begin(S), end(S));
        vector<vector<pair<long long,long long>>> path(intervals.size(), vector<pair<long long, long long>>(4));
        priority_queue<array<long long,3>,vector<array<long long,3>>,greater<array<long long,3>>> q[4];
        vector<pair<long long,long long>> best(4,{0,-1});
        vector<int> res(4,intervals.size());
        long long cost = 0;
        auto restore = [&](int x, int k) {
            vector<int> res;
            for(int i = k; i >= 0 and x >= 0; i--) {
                res.push_back(x);
                x = path[x][i].second;
            }
            sort(begin(res), end(res));
            return res;
        };
        for(auto& [s,e,w,idx] : S) {
            for(int i = 0; i < 4; i++) {
                while(q[i].size() and q[i].top().front() < s) {
                    auto [_,idx,sum] = q[i].top(); q[i].pop();
                    best[i] = max(best[i], {sum, -idx});
                }
            }
            for(int i = 0; i <= 3; i++) {
                if(!best[i].first) continue;
                path[idx][i] = {best[i].first + w, -best[i].second};
                cost = max(cost, best[i].first + w);
                if(i != 3) q[i+1].push({e,idx,best[i].first + w});
            }
            q[1].push({e,idx,w});
            path[idx][0] = {w,1};
            cost = max(cost, w);
        }
        for(int i = 0; i < S.size(); i++) {
            for(int j = 0; j <= 3; j++) {
                if(path[i][j].first != cost) continue;
                res = min(res, restore(i,j));
            }
        }

        return res;
    }
};