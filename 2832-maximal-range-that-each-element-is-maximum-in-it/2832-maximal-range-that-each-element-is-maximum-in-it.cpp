int uf[101010], sz[101010];
int find(int u) {
    return uf[u] == u? u : uf[u] = find(uf[u]);
}
int uni(int u, int v) {
    int pu = find(u), pv = find(v);
    sz[pu] = sz[pv] = sz[pu] + sz[pv];
    uf[pu] = uf[pv] = min(pu,pv);
    return sz[pu];
}
class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> ord(n), on(n), res(n);
        for(int i = 0; i < n; i++) ord[i] = uf[i] = i, sz[i] = 1;
        sort(begin(ord), end(ord), [&](int i, int j) {return nums[i]<nums[j];});
        for(int i = 0; i < n; i++) {
            int p = ord[i], ma = 1;
            on[p] = true;
            if(p - 1 >= 0 and on[p-1]) {
                ma = max(ma, uni(p,p-1));
            }
            if(p + 1 < n and on[p+1]) {
                ma = max(ma, uni(p,p+1));
            }
            res[p] = ma;
        }
        return res;
    }
};