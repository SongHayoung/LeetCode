class Solution {
    int uf[101010];
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu,pv);
    }
public:
    int minimumHammingDistance(vector<int>& A, vector<int>& B, vector<vector<int>>& allowedSwaps) {
        int n = A.size();
        for(int i = 0; i < n; i++) uf[i] = i;
        for(auto a : allowedSwaps) {
            int u = a[0], v = a[1];
            uni(u,v);
        }
        unordered_map<int, unordered_map<int, int>> freq;
        for(int i = 0; i < n; i++) {
            freq[find(i)][A[i]]++;
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            int f = find(i);
            if(!freq[f][B[i]]) res++;
            else freq[f][B[i]]--;
        }
        return res;
    }
};