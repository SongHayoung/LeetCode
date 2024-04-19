unordered_map<int, int> uf;
int find(int u) {
    if(!uf.count(u)) {
        return uf[u] = u;
    }
    return uf[u] == u ? u : uf[u] = find(uf[u]);
}
void uni(int u, int v) {
    int pu = find(u), pv = find(v);
    if(pu == pv) return;
    uf[pu] = uf[pv] = max(pu,pv);
}
int best(int x) {
    if(!uf.count(x)) return x;
    return find(x) + 1;
}
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        uf.clear();
        uf.reserve(nums.size());
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