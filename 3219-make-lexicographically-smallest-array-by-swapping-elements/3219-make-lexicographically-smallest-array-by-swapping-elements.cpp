

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
    vector<int> lexicographicallySmallestArray(vector<int>& A, int limit) {
        vector<int> s = A;
        sort(begin(s), end(s));
        s.erase(unique(begin(s), end(s)), end(s));
        unordered_map<int, int> ref;
        for(int i = 0; i < s.size(); i++) {
            ref[s[i]] = i;
        }
        for(int i = 0; i < s.size(); i++) uf[i] = i;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i+1] - s[i] <= limit) uni(i,i+1);
        }
        unordered_map<int, deque<int>> gr;
        for(int i = 0; i < A.size(); i++) {
            int f = find(ref[A[i]]);
            gr[f].push_back(A[i]);
        }
        for(auto& [k,v] : gr) sort(begin(v), end(v));
        vector<int> res(A.size());
        for(int i = 0; i < A.size(); i ++) {
            int f = find(ref[A[i]]);
            res[i] = gr[f].front();
            gr[f].pop_front();
        }
        return res;
    }
};

