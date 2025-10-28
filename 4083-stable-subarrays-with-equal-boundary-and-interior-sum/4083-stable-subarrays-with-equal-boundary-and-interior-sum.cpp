class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        if (n < 3) return 0;
        vector<long long> pre(n+1,0);
        for (int i = 0; i < n; ++i) pre[i+1] = pre[i] + capacity[i];
        struct PairHash {
            size_t operator()(pair<long long,long long> const& p) const noexcept {
                return std::hash<long long>()(p.first) ^ (std::hash<long long>()(p.second) << 1);
            }
        };
        unordered_map<pair<long long,long long>, long long, PairHash> mp;
        long long ans = 0;
        for (int r = 2; r < n; ++r) {
            int l = r - 2;
            mp[{(long long)capacity[l], pre[l+1]}]++;
            pair<long long,long long> target = {(long long)capacity[r], pre[r] - capacity[r]};
            auto it = mp.find(target);
            if (it != mp.end()) ans += it->second;
        }
        return ans;
    }
};