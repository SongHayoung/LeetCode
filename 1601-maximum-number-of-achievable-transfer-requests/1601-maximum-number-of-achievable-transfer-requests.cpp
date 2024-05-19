class Solution {
    bool bit(int x, int p) {
        return (x>>p) & 1;
    }
public:
    int maximumRequests(int n, vector<vector<int>>& A) {
        int res = 0, x = A.size();
        for(int mask = 0; mask < 1<<x; mask++) {
            int now = 0;
            vector<int> buc(n);
            for(int j = 0; j < x; j++) {
                if(!bit(mask,j)) continue;
                int u = A[j][0], v = A[j][1];
                now++;
                buc[u] -= 1, buc[v] += 1;
            }
            if(now > res) {
                bool ok = true;
                for(int i = 0; i < n and ok; i++) if(buc[i]) ok = false;
                if(ok) res = max(res,now);
            }
        }
        return res;
    }
};