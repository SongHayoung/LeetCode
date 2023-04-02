class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& A, int k) {
        vector<int> res(n, INT_MAX);
        for(auto a : A) res[a] = -1;
        res[p] = 0;
        set<int> st1, st2;
        for(int i = 0; i < n; i++) if(res[i] == INT_MAX) {
            if(i & 1) st1.insert(i);
            else st2.insert(i);
        }
        queue<int> q;
        q.push(p);
        while(q.size()) {
            int u = q.front(); q.pop();
            int l = u - k + 1>= 0 ? u - k + 1: k - u - 1;
            int r = u + k - 1 < n ? u + k - 1 : n - k + (n - u - 1);
            if(l > r) swap(l,r);
            vector<int> erase;
            set<int>& st = (l & 1 ? st1 : st2);
            for(auto it = st.lower_bound(l); it != end(st) and *it <= r; it++) {
                erase.push_back(*it);
                res[*it] = res[u] + 1;
                q.push(*it);
            }
            for(auto e : erase) st.erase(e);
        }
        for(int i = 0; i < n; i++) if(res[i] == INT_MAX) res[i] = -1;
        return res;
    }
};

