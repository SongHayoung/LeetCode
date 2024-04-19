unordered_map<int, int> uf, cnt;
int find(int u) {
    if(!uf.count(u)) {
        cnt[u] = 1;
        return uf[u] = u;
    }
    return uf[u] == u ? u : uf[u] = find(uf[u]);
}
void uni(int u, int v) {
    int pu = find(u), pv = find(v);
    if(pu == pv) return;
    cnt[pu] = cnt[pv] = cnt[pu] + cnt[pv];
    uf[pu] = uf[pv] = min(pu,pv);
}
int best(int x) {
    if(!uf.count(x)) return x;
    int root = find(x), max = cnt[root];
    return root + max;
}
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        uf.clear();
        cnt.clear();
        int res = 0;
        for(auto& x : nums) {
            int now = best(x);
            res += now - x;
            find(now);
            if(uf.count(now - 1)) uni(now, now - 1);
            if(uf.count(now + 1)) uni(now, now + 1);
        }
        return res;
    }
};