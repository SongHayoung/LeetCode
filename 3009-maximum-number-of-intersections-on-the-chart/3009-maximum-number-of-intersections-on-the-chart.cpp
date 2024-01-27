class Solution {
public:
    int maxIntersectionCount(vector<int>& y) {
        unordered_map<long long, int> mp;
        for(int i = 0; i < y.size() - 1; i++) {
            long long a = y[i], b = y[i+1];
            a *= 2, b *= 2;
            if(a > b) {
                mp[b] += 1;
                mp[a] -= 1;
            } else {
                mp[a+1] += 1;
                mp[b+1] -= 1;
            }
        }
        vector<pair<long long, long long>> S;
        for(auto& [k,v] : mp) S.push_back({k,v});
        sort(begin(S), end(S));
        int res = 0, pre = 0, app = y[0] * 2;
        for(auto& [k,v] : S) {
            pre += v;
            res = max(res, pre + (k == app));
        }
        return res;
    }
};