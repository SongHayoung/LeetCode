
const int MAX_N = 101010;
long long uf1[MAX_N], cnt[MAX_N];
long long find(long long uf[], int u) {
    return uf[u] == u ? u : uf[u] = find(uf, uf[u]);
}
bool uni(long long uf[], int u, int v) {
    int pu = find(uf,u), pv = find(uf, v);
    if(pu == pv) return false;
    cnt[pu] = cnt[pv] = cnt[pu] + cnt[pv];
    uf[pu] = uf[pv] = min(pu,pv);
    return true;
}
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        for(int i = 0; i < n; i++) uf1[i] = i, cnt[i] = 1;
        multiset<int> ms, udt;
        vector<array<int,3>> A;
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2], fl = e[3];
            if(fl) {
                ms.insert(w);
                if(!uni(uf1,u,v)) return -1;
            } else A.push_back({w,u,v});
        }
        sort(rbegin(A), rend(A));
        for(auto& [w,u,v] : A) {
            if(cnt[0] == n) break;
            if(uni(uf1,u,v)) {
                if(k > 0) {
                    if(ms.size() == 0 or *begin(ms) > w) {
                        --k, udt.insert(w * 2), ms.insert(w * 2);
                    }
                } else {
                    if(udt.size() == 0) ms.insert(w);
                    else {
                        int ma = *udt.rbegin();
                        ms.erase(ms.find(ma));
                        udt.erase(udt.find(ma));
                        ma /= 2;
                        ms.insert(ma);
                        ms.insert(w * 2);
                        udt.insert(w * 2);
                    }
                }
            }
        }
        return cnt[0] == n ? *begin(ms) : -1;
    }
};
