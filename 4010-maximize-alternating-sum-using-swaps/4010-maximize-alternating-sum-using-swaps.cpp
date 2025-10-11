int uf[101010];
int find(int u) {
    return uf[u] == u ? u : uf[u] = find(uf[u]);
}
void uni(int u, int v) {
    int pu = find(u), pv = find(v);
    uf[pu] = uf[pv] = min(pu,pv);
}
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        iota(begin(uf), end(uf), 0);
        for(auto& s : swaps) uni(s[0], s[1]);
        unordered_map<int, vector<int>> vals;
        unordered_map<int, int> add;
        for(int i = 0; i < nums.size(); i++) {
            int pi = find(i);
            vals[pi].push_back(nums[i]);
            if(i % 2 == 0) add[pi]++;
        }
        long long res = 0;
        for(auto& [k,v] : vals) {
            sort(rbegin(v), rend(v));
            int plus = add[k];
            for(int i = 0; i < v.size(); i++) res += v[i] * (i < plus ? 1 : -1);
        }
        return res;
    }
};