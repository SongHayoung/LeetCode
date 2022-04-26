#define all(a) begin(a), end(a)

class Solution {
    int seive[100001];
    int uf[100001];
    void setSeive(int n) {
        for(int i = 2; i * i <= n; i++) {
            if(seive[i]) continue;
            for(int j = i * i; j <= n; j += i) {
                if(seive[j]) continue;
                seive[j] = i;
            }
        }
    }
    
    unordered_set<int> factorsOf(int n) {
        unordered_set<int> factor;
        while(seive[n]) {
            factor.insert(seive[n]);
            n /= seive[n];
        }
        factor.insert(n);
        return factor;
    }
    int find(int n) {
        return uf[n] == n ? n : uf[n] = find(uf[n]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu,pv);
    }
public:
    bool gcdSort(vector<int>& A) {
        memset(seive, 0, sizeof seive);
        vector<int> S = A;
        sort(all(S));
        setSeive(S.back());
        for(int i = 1; i <= S.back(); i++) uf[i] = i;
        int prv = -1;
        for(auto& s : S) {
            if(prv == s) continue;
            prv = s;
            for(auto& f : factorsOf(s)) {
                uni(s,f);
            }
        }
        int n = A.size();
        for(int i = 0; i < n; i++) {
            if(find(S[i]) != find(A[i]))
                return false;
        }
        return true;
    }
};