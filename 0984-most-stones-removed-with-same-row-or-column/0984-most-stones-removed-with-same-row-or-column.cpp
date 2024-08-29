int uf[202020];
int find(int u) {
    return uf[u] == u ? u : uf[u] = find(uf[u]);
}
void uni(int u, int v) {
    int pu = find(u), pv = find(v);
    uf[pu] = uf[pv] = min(pu,pv);
}
class Solution {
public:
    int removeStones(vector<vector<int>>& A) {
        for(int i = 0; i < 202020; i++) uf[i] = i;
        for(auto& s : A) uni(s[0], s[1] + 100001);
        unordered_map<int,int> freq;
        for(auto& s : A) freq[find(s[0])]++;
        int res = 0;
        for(auto& [k,v] : freq) res += v-1;
        return res;
    }
};