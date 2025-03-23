struct Info {
    int f, t;
    long long w;

    bool operator()(Info a, Info b) {
        return a.w > b.w;
    }
};

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads, int m = 1e9 + 7) {
        unordered_map<int, vector<pair<int, int>>> d;
        unordered_map<int, pair<long long, int>> v{{0, {1ll, 1}}};
        priority_queue<Info, vector<Info>, Info> pq;
        for(auto& r : roads) {
            d[r[0]].push_back({r[2], r[1]});
            d[r[1]].push_back({r[2], r[0]});
        }

        for(auto& r : d[0]) {
            pq.push({.f = 0, .t = r.second, .w = r.first});
        }

        while(!pq.empty()) {
            auto info = pq.top();
            pq.pop();
            if(v.count(info.t)) {
                if(v[info.t].first >= info.w) v[info.t].second = (v[info.t].second + v[info.f].second) % m;
                continue;
            }
            v[info.t] = {info.w, v[info.f].second};
            for(auto& r : d[info.t]) {
                if(v.count(r.second)) continue;
                pq.push({.f = info.t, .t = r.second, .w = info.w + r.first});
            }
        }

        return v[n - 1].second;
    }
};