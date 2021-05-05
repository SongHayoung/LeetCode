class Solution {
    void chk(vector<bool>& v, vector<vector<int>>& c, int& n, int p) {
        v[p] = true;
        for(int i = 0; i < n; i++) {
            if(c[i][p] && !v[i])
                chk(v,c,n,i);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = 0;
        vector<bool> v(n, false);
        for(int i = 0; i < n; i++) {
            if(v[i]) continue;
            res++;
            chk(v, isConnected, n, i);
        }
        return res;
    }
};
