class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long res = 0, mi = INT_MAX;
        unordered_map<long long, pair<long long, long long>> freq;
        for(auto b : basket1) freq[b].first += 1;
        for(auto b : basket2) freq[b].second += 1;
        map<long long, long long> req1, req2;
        for(auto [k,v] : freq) {
            mi = min(mi, k);
            if((v.first + v.second) & 1) return -1;
            if(v.first == v.second) continue;
            auto [f,s] = v;
            long long h = (f + s) / 2;
            if(f > s) req1[k] += f - h;
            else req2[k] += s - h;
        }
        if(req1.size() == 0) return 0;
        for(auto i = begin(req1), j = prev(end(req2)); i != end(req1); i++) {
            while(i->second) {
                if(j->second == 0) j = prev(j);
                else {
                    res += min({i->first, j->first, mi * 2});
                    i->second -= 1;
                    j->second -= 1;
                }
            }
        }
        return res;
    }
};