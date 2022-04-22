class Solution {
    int seg[400000];
    void update(int u, int s, int e, int l, int r, int v) {
        if(r < s or e < l) return;
        if(l <= s and e <= r) {
            seg[u] = v;
            return;
        }
        int m = (s + e) >> 1;
        update(u * 2, s, m, l, r, v);
        update(u * 2 + 1, m + 1, e, l, r, v);
        seg[u] = seg[u * 2] & seg[u * 2 + 1];
    }
    
    int query(int u, int s, int e, int l, int r) {
        if(r < s or e < l) return INT_MAX;   
        if(l <= s and e <= r) return seg[u];
        int m = (s + e) >> 1;
        return query(u * 2, s, m, l, r) & query(u * 2 + 1, m + 1, e, l, r);
    }
    int ternarySearch(int l, int r, int n, int& t) {
        int res = INT_MAX;
        int s = l, e = r;
        while(l < r) {
            int m = (l + r + 1) / 2;
            int q = query(1, 1, n, l, m);
            if(q >= t) l = m;
            else r = m - 1;
        }
        res = min(res, abs(t - query(1,1,n, s,l)));
        if(l + 1 <= n)
            res = min(res, abs(t - query(1,1,n,s,l+1)));
        if(l - 1 >= s)
            res = min(res, abs(t - query(1,1,n,s,l-1)));
        return res;
        
    }
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size(), l = 1, r = n, res = INT_MAX;
        for(int i = 0; i < n; i++) {
            update(1, 1, n, i + 1, i + 1, arr[i]);
        }
        
        for(int i = 1; i <= n; i++)
            res = min(res, ternarySearch(i,n,n,target));
        
        return res;
    }
};