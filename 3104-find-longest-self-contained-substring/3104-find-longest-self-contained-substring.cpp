class Solution {
public:
    int maxSubstringLength(string s) {
        int res = -1;
        vector<pair<int, int>> best(26, {INT_MAX,INT_MIN});
        vector<vector<int>> freq;
        vector<int> f(26);
        for(int i = 0; i < s.length(); i++) {
            pair<int,int>& p = best[s[i]-'a'];
            p.first = min(p.first, i);
            p.second = i;
            f[s[i]-'a']++;
            freq.push_back(f);
        }
        auto query = [&](int l, int r) {
            vector<int> res = freq[r];
            if(l) {
                for(int i = 0; i < 26; i++) res[i] -= freq[l-1][i];
            }
            return res;
        };
        vector<pair<int,int>> range;
        for(int i = 0; i < 26; i++) {
            if(best[i].first == INT_MAX) continue;
            vector<int> vis(26);
            queue<int> q;
            int l = best[i].first, r = best[i].second;
            auto push = [&](int x) {
                if(!vis[x]) {
                    q.push(x);
                    vis[x] = true;
                    return true;
                }
                return false;
            };
            push(i);
            while(q.size()) {
                auto u = q.front(); q.pop();
                auto [le,ri] = best[u];
                l = min(l, le), r = max(r, ri);
                vector<int> now = query(l,r);
                for(int i = 0; i < 26; i++) if(now[i]) push(i);
            }
            if(l == 0 and r == s.length() - 1) continue;
            res = max(res, r - l + 1);
            range.push_back({l,r});
        }
        sort(begin(range), end(range));
        for(int i = 0; i < range.size(); i++) {
            int l = range[i].first, r = range[i].second;
            for(int j = i + 1; j < range.size(); j++) {
                if(r + 1 == range[j].first) {
                    r = range[j].second;
                }
                if(l == 0 and r == s.length() - 1) continue;
                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};