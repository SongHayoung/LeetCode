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
    int maxActivated(vector<vector<int>>& points) {
        iota(begin(uf), end(uf), 0);
        unordered_map<int,int> x,y;
        for(int i = 0; i < points.size(); i++) {
            int xx = points[i][0], yy = points[i][1];
            if(x.count(xx)) uni(i,x[xx]);
            else x[xx] = i;
            
            if(y.count(yy)) uni(i, y[yy]);
            else y[yy] = i;
        }
        unordered_map<int,int> cnt;
        for(int i = 0; i < points.size(); i++) cnt[find(i)]++;
        vector<int> S;
        for(auto& [_,v] : cnt) S.push_back(v);
        sort(rbegin(S), rend(S));
        if(S.size() == 1) return S[0] + 1;
        return S[0] + S[1] + 1;
    }
};
