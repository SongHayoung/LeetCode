class Solution {
    long long uf[101010];
    long long find(long long u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(long long u, long long v) {
        auto pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu,pv);
    }
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        iota(begin(uf), end(uf) ,0);
        for(int i = 0; i < arr.size(); i++) uni(i, (i + k) % arr.size());
        unordered_map<long long, vector<int>> mp;
        for(int i = 0; i < arr.size(); i++) mp[find(i)].push_back(arr[i]);
        long long res = 0;
        for(auto& [k,vec] : mp) {
            sort(begin(vec), end(vec));
            long long sum = 0, med = vec[(vec.size() - 1) / 2];
            for(auto v : vec) sum += v;
            for(auto& v : vec) res += abs(v - med);
        }
        return res;
    }
};
